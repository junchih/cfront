/*

 *      Copyright (c) 1984 AT&T
 *      All Rights Reserved

 *      THIS IS UNPUBLISHED PROPRIETARY SOURCE 
 *      CODE OF AT&T.
 *      The copyright notice above does not 
 *      evidence any actual or intended
 *      publication of such source code.

 */
/********************************************************************/
/*
LEVEL 1.20 OF ncsl.c
LAST CHANGED: 83/12/17 16:55:11
modified by G. Patton 7/4/83 fixed ~ and ~~ for PL1 and C
modified by G. Patton 7/18/83 droped 1st char for pl1 except for ~ and tab.
	Fixed loop in pl1 for ~.
modified by G. Patton 7/27/83 fixed count of blank line after a comment in pl1
	and c. still error if blanks on the blnk line.
modified by G. Patton 12/15/83 to not take $# as cmnt in shell.
modified by G. Patton 12/16/83 to add psb and dbd as langs  
modified by R. Murray 1/14/88 to add C++ comments
modified by M. Shannon 3/18/88 to not eat newline at end of C++ `//' comments.
modified by D. Mancl 12/9/88 to fix the two previous fixes
modified by M. Shannon 2/28/89 to fix the single-quote, double-quote and
	backslash state machine for C/C++.
COMPILE COMMAND: cc -o ncsl  ncsl.c
*/
/* modifications by G. Patton included merging the main and subs in
*  one file and adding the surce for three subs for string manipulation
*  stncmp, strtok, and strpbrk (used by strpbrk). The string 
*  manipulation routines need only be added for IBM. 
*  STRSPN is already in the IBM C library.    */
/********************************************************************/
static char	*sccs = "@(#)ncsl.c	1.20";
#include	<stdio.h>
#define	SETUPFILE(mes,rw) if((fp = fopen("file",rw)) == NULL) \
		{ dum = fprintf(stderr,mes);\
		  exit(-1); }


/* This program accepts from the standard input source code in 
   one of the specified languages, deletes comments and blank 
   lines and prints it to standard output. Most of the time, the
   the program acts as a filter for other programs.
   The program must be given an argument of 
   the language that the input file is coded in so that the
   proper commenting procedure will be invoked.

	ex.  ncsl -lpli

   Legal parameters are:	pli or pl1
				c
				c++
				cobol
				fortran
				leap
				shell
				dtp
				comp
				bal
                                dbd
                                psb
				sal
				snoflake
				spitbol
				jcl
				mark4
				m11
				srt
				lke
				lr
				parms
				errupdt
				makefile
				lex
				yacc
				as
				pdpas

upper case versions of these parameters are accepted.

Several key letters can be used in the calling argument.  They are;
     -l = the language (required)
     -i = the input file name (optinal, if not specified stdin)
     -o = the output for filtered source (optional) default stdout
     -s = the stat file (optional) default stderr
     -c = if set no headings appear over statistics
     -g = if set invalid lang names will process as parms
     -f = filename of input (optional) when get file on pipe set name
*/
int quote;
int squote;
int dollar; /* a flag set if char is a dollar in shell */
int dum; /* a dummy var assigned to values returned from functions */
int duml; /* a dummyn var assigned to long values returned from time */
char *dumc; /* a dummy var to assign returns from strcpy */
int salf = 0; /* this flag set for lang  = sal is checked in getch so
		leading blanks arent pulled from pl1 type code when 
		checking pl1 part of sal and thus operators can be
		distinguished from labels */
int pl1f = 0; /* this flag set for lang pl1 is checked in getcr */
int cplusf = 0; /* This flag set for C++ // comments.*/
int fstf = 0; /* this flag is set to 1 if 1st col of pl1 used in
	cmtchk so dont count blank line if only col 1 */
	/* set in getcr */
char *optarg; /* needed for getopt (3c) added for portability to end */
	/* start of vars for comment counting */
	int cmntf = 0; /* comment flag >0 means comment in line */
	int commentc = 0; /* count of comment lines */
	int codef = 0; /* code flag >0 = prog. statement */
	int codec = 0; /* count of non-comment lines */
	int blankf = 0; /* blank line flag */
	int blankc = 0; /* count of blank lines */
	int bothc = 0; /* count of lines both comm and non-comment */
	int linecnt = 0; /* count of total lines input */
	int linesav = 0; /* save line count for 2 pass files */
	int blanksav = 0; /* save blank count for 2 pass files */
	int comsav = 0; /* save comment count from first pass */
	/* end of vars used for comment counting */

	/* vars used for input parsing */
	int lflag = 0; /* flag to show if language was specififed */
	int iflag = 0; /* flag to show if input file specified */
	int fflag = 0; /* flag to show name of input given as arg */
			/* this is used when input down pipe */
	int oflag = 0; /* flag to show output file specified */
	int sflag = 0; /* flag to so stat file specified */
	int cflag = 1; /* flag on if want headings */
	int eflag = 0; /* flag set if error in args */
	int gflag = 0; /* flag to go ahead and process unknown lang */
	/* end of vars used for input parsing */
/* stuff needed for time and ctime */
struct	tm {	/* see ctime(3) */
	int	tm_sec;
	int	tm_min;
	int	tm_hour;
	int	tm_mday;
	int	tm_mon;
	int	tm_year;
	int	tm_wday;
	int	tm_yday;
	int	tm_isdst;
};
	long tbuf, time();
	struct tm *tim, *gmtime(), *localtime();
/* end of stuff needed for time */
main(argc,argv)
int argc;
char **argv;
{
	char *filein;
	int i,j; /* used to get right bytes of filename */
	char *filen; /* holds name of file when it comes donw pipe */
	char *fileout;
	char *filest;  /* name of file stats to go out to */
	int d;
	char *lang;
	register int c, backslash;
	char QUOTE;

	FILE *fp, *fopen(), *freopen();


	while ((d = getopt (argc,argv,"l:o:s:i:f:cg")) != EOF)
	{
		switch (d)
		{
		case 'l': /* specify langauge name */
			lflag = 1;
			lang = optarg;
			break;
		case 'o':  /* specify output file name */
			oflag = 1;
			fileout = optarg;
			break;
		case 's':  /* specify statistics file */
			sflag = 1;
			filest = optarg;
			break;
		case 'c':       /* heading flag, if 1 get headings */
			cflag = 0;
			break;
		case 'i':    /* get name of input file if specified */
			iflag = 1;
			filein = optarg;
			break;
		case 'f': /* get the name of in file as arg 
			when it comes down pipe */
			fflag = 1;
			filen = optarg;
			break;
		case 'g':
			gflag = 1;
			break;
		case '?':
			eflag = 1;
		}
		if (eflag)
		{
		dum = fprintf (stderr,
   "usage: -llang \[-iinfile -ooutfile -sstatfile -c -g -ffile\]\n");
		exit (-1);
		}
	}
	if (! lflag)
	{
		dum =  fprintf (stderr,
		"language not specified use -l option\n");
		if (gflag == 0) exit(-1); /* if no gflag abort */
		lang = "unk"; /* if no lang spec say unk dos as parms */
	}

	/* set up files */
	if (iflag)
	{
		if (freopen (filein,"r",stdin) == NULL)
		{
			dum =  fprintf(stderr,
			"cannot open file %s for input \n",filein);
			exit(-1);
		}
	}
	else
	{
		if (fflag) filein = filen; /* get file name from arg */
		else filein = "unknown"; 
	}
	if (oflag)
	{
		if (freopen(fileout,"w",stdout) == NULL)
		{
			dum =  fprintf(stderr,
			"cannot open file %s for output \n",fileout);
			exit (-1);
		}
	}
	backslash = 0;
	quote = 0;
	squote = 0;
	dollar = 0; /* set flag to 0 to indicate no dollar char found. */
	QUOTE = '\'';

	if ( (strcmp(lang,"pli") == 0) || (strcmp(lang,"pl1") == 0) 
		|| (strcmp(lang,"PLI") == 0) 
		|| (strcmp(lang,"PL1") == 0) )
	{
		pl1f = 1;  /* set flag checked in getcr to skip first col */
		previnit();
		while ((c= getcr(stdin)) != EOF)
		{
			/* A quote mechanism is turned on and off for
			   quoted strings.  This is to avoid parsing
			   comments imbedded within quotes.
			*/

			if(c == QUOTE) quote = ++quote % 2;
			if ( !fstf || c == '~' )
				{
				dum = putc(c,stdout);
				}
		}
	}

	else if ((strcmp(lang,"c") == 0) ||
		(strcmp(lang,"C") == 0) ||
		(strcmp(lang,"c++") == 0) ||
		(strcmp(lang,"C++") == 0) ||
		(strcmp(lang,"LEAP") == 0) ||
		 (strcmp(lang,"leap") == 0))
	{
		int instring = 0;
		int incharconst = 0;

		if (strcmp(lang,"c++")==0 || strcmp(lang,"C++")==0)
			cplusf=1;
		QUOTE = '\"';
		previnit();
		while ((c= getcr(stdin)) != EOF)
		{
#if 1
			if (instring) {
				if (c == '\\')
					backslash = ++backslash & 1;
				else
				if (c == QUOTE && !backslash)
					instring = 0;
			} else {
				if (incharconst) {
					if (c == '\\')
						backslash = ++backslash & 1;
					else
					if (c == '\'' && !backslash)
						incharconst = 0;
				} else {
					if (c == '\\')
						backslash = ++backslash & 1;
					else
					if (c == '\'' && !backslash)
						incharconst = 1;
					else
					if (c == QUOTE && !backslash)
						instring = 1;
				}
			}
#else
			if ( ((c == '\'') && (!quote)) || (c == '\\' ) )
				backslash = ++backslash%2;
			else 
			{

			/* A quote mechanism is turned on and off here
			   also in conjunction with a backslash 
			   mechanism to avoid parsing special 
			   characters and comments imbedded 
			   within quotes.
			*/
				if(c == QUOTE)
				{
					if(backslash) backslash = 0;
					else quote = ++quote%2;
				}
				else backslash = 0;
			}
#endif
			dum = putc(c,stdout);
		}
	}

	else if ((strcmp(lang,"snoflake") == 0) || 
		(strcmp(lang,"SNOFLAKE") == 0) ||
		(strcmp(lang,"SPITBOL") == 0) ||
		(strcmp(lang,"spitbol") == 0))
	{
		snobolcomment(stdin,stdout);
	}

	else if ((strcmp(lang,"fortran") == 0) ||
		(strcmp (lang,"FORTRAN") == 0) )
	{
		fortrancomment(stdin,stdout);
	}
	else if ((strcmp(lang,"cobol") == 0) ||
		(strcmp(lang,"COBOL") == 0) )
	{
		cobolcomment(stdin,stdout);
	}

	else if ((strcmp(lang,"dtp") == 0)  ||
		(strcmp(lang,"DTP") == 0) )
	{
		/* first remove dtp type comments, then process
		   like cobol
		*/

		SETUPFILE("CANNOT OPEN FILE FOR WRITING","w");
		dtpcomment(stdin,fp);
		dum = fclose(fp);
		linesav = linecnt; /* save orig linecount */
		blanksav = blankc; /* save count of blanks pulled */
		comsav = commentc; /* save number of dtp comments */
		commentc = 0; /* reset comment counter */
		codec = 0; /* reset code counter */
		SETUPFILE("CANNOT OPEN FILE FOR READING","r");
		cobolcomment(fp,stdout);
		dum = fclose(fp);
		linecnt = linesav; /* restore orig linecount */
		blankc = blanksav; /* restore count of blanks */
		commentc = commentc + comsav; /* add comment counts */
	}

	else if ((strcmp(lang,"sal") == 0)  ||
		(strcmp(lang,"SAL") == 0) )
	{
		salf = 1; /* set salflag so getch will not pull lead
			blanks and bal can distinguish labels /*
		/* first remove pl1 type comments,
		then process like bal.
		*/

		SETUPFILE("CANNOT OPEN FILE FOR WRITING","w");
		while ((c=getcr(stdin)) != EOF)
		{
			/* took this out because BAL can have open
			ended quotes which eats up the comments.
			if (c == QUOTE) quote = ++quote%2; */
			dum = putc(c,fp);
		}
		dum = fclose(fp);
		linesav = linecnt; /* save orig linecount */
		blanksav = blankc; /* save count of blanks pulled */
		codec=0; /* reset code counter */
		blankc=0; /* reset blank counter */

		previnit();
		SETUPFILE("CANNOT OPEN FILE FOR READING","r");
		balcomment(fp,stdout);
		linecnt = linesav; /* restore orig linecount */
		blankc = blanksav; /* restore count of blanks */
	}

	else if ((strcmp(lang,"shell") == 0) ||
		(strcmp(lang,"SHELL") == 0 ) )
	{
		while ((c= getc(stdin)) != EOF )
		{
			if ((c == '~') && (codef == 0) &&
			    (cmntf == 0))
			{
				if((c=getc(stdin)) == '~')
				{
				    while (((c=getc(stdin)) != '\n')
					&& (c != EOF));
				    ++cmntf;
				    cmtchk();
				}
				else
				{
					++codef;
					dum = putc ('~',stdout); 
					/* write orig char */
					dum = putc (c,stdout); 
					/* write next char */
				}
			}
			else if ((c == ' ') && (codef == 0) &&
				(cmntf == 0)); /* pull lead blanks */
			else if ((c == '\t') && (codef == 0) &&
			        (cmntf == 0)); /* pull lead tabs */
			else if (c == '\'') /* handle single quote */
			{
				if (backslash || quote) backslash = 0;
				else squote = ++squote%2;
				dum = putc (c,stdout);
			}
			else if (c == '\\')
			{
				dum = putc (c,stdout);
				backslash = ++backslash%2;
			}
			else if (c == '"') 
			{
				if (backslash || squote) backslash = 0;
				else quote = ++quote%2;
				dum = putc (c,stdout);
			}
			else if (c == '\n')
			{
				if (codef > 0) dum = putc (c,stdout);
				cmtchk();
			}
			else if ((c == '#') && (!quote) && 
				(!backslash) && (!squote) && (!dollar)) 
				/* strip line */
			{
				while (((c= getc(stdin)) != EOF) &&
					(c != '\n') );
				++cmntf;
				/* write end of line if not blank */
				if (codef > 0) dum = putc (c,stdout);
				cmtchk();
			}
			else
			{
				dollar = 0; /* reset dollar flag to 0 */
				if ( c == '$') dollar = 1; /* set dollar flag */
				/* dollar flag set so  not a comment */
				backslash=0;
				 ++codef;
				dum = putc (c,stdout);
			}
		}
	}
	else if ((strcmp (lang,"m11") == 0) ||
		(strcmp(lang,"M11") == 0 ) )
	{
		while ((c = getc(stdin)) != EOF)
		{
			if ((c == '~') && (codef == 0) &&
			    (cmntf == 0))
			{
				if((c=getc(stdin)) == '~')
				{
				   while (((c=getc(stdin)) != '\n')
				   && (c != EOF));
				   ++cmntf;
				   cmtchk();
				}
				else
				{
					++codef;
					dum = putc ('~',stdout); 
					/* write orig char */
					dum = putc (c,stdout); 
					/* write next char */
				}
			}
			else if ((c == ' ') && (codef == 0) && 
				(cmntf == 0)); /* pull lead blanks */
			else if ((c == '\t') && (codef == 0) &&
				(cmntf == 0)); /* pull lead tdabs */
			else if (c == '\n') /* check end of line */
			{                /* must do before check ; */
				if (codef > 0) dum = putc(c,stdout); 
				/* non blank */
				cmtchk();
			}
			else if (c == '\;') /* a comment to EOL */
			{
				++cmntf;
				while (((c=getc(stdin)) != EOF) &&
				        (c != '\n') ); /* strip cmt */
				if (codef > 0) dum = putc (c,stdout);
				cmtchk();
			}
			else   /* it must be non comment */
			{
				++codef;
				dum= putc (c,stdout);
			}
		}
	}
	else if ((strcmp(lang,"bal") == 0) ||
		(strcmp(lang,"BAL") == 0) ||
                (strcmp(lang,"psb") == 0) ||
                (strcmp(lang,"PSB") == 0) ||
                (strcmp(lang,"dbd") == 0) ||
                (strcmp(lang,"DBD") == 0) )
	{
		balcomment(stdin,stdout);
	}

	else if ((strcmp(lang,"jcl") == 0)  ||
		(strcmp(lang,"JCL") == 0) )
	{
		jclcomment(stdin,stdout);
	}

	else if ((strcmp(lang,"dirjcl") == 0)  ||
		(strcmp(lang,"DIRJCL") == 0 ) )
	{
		dirjclcomment(stdin,stdout);
	}

	else if ((strcmp(lang,"comp") == 0)  ||
		(strcmp(lang,"COMP") == 0) )
	{
		snobolcomment(stdin,stdout);
	}

	else if ((strcmp(lang,"mark4") == 0) ||
		(strcmp(lang,"MARK4") == 0) )
	{
		mark4comment(stdin,stdout);
	}

	else if ((strcmp(lang,"srt") == 0) ||
		(strcmp(lang,"SRT") == 0 ) )
	{
		snobolcomment(stdin,stdout);
	}

	else if ((strcmp(lang,"lke") == 0) ||
		(strcmp(lang,"LKE") == 0) )
	{
		lkecomment(stdin,stdout);
	}

	else if ((strcmp(lang,"lr") == 0) ||
		(strcmp(lang,"LR") == 0) )
	{
		lrcomment(stdin,stdout);
	}
	else if ((strcmp(lang,"parms") == 0)  ||
		(strcmp(lang,"PARMS") == 0) ||
		(strcmp(lang,"ERRUPDT") == 0) ||
		 (strcmp(lang,"errupdt") == 0))
	{
		nocomment(stdin,stdout);
	}

 	else if ((strcmp (lang,"makefile") == 0) ||
 		(strcmp(lang, "MAKEFILE") == 0))
 	{
 		while((c = getc(stdin)) != EOF)
 		{
 			if( c == '#')
 			/* Strip line -- this is a comment */
 			{
 				while(((c = getc(stdin)) != EOF) &&
 					(c != '\n'));
 				++cmntf;
 				/* Write End-of-line if not blank */
 				if(codef > 0) dum = putc(c, stdout);
 				cmtchk();
 			}
 			else if (c == '\n')
 			{
 				if(codef > 0) dum = putc(c, stdout);
 				cmtchk();
 			}
 			else if ((c == ' ') && (codef == 0) &&
 				(cmntf == 0));	/* Pull lead blanks */
 			else if ((c == '\t') && (codef == 0) &&
 				(cmntf == 0));	/* Pull lead tabs */
 			else
 			{
 				++codef;
 				dum = putc(c ,stdout);
 			}
 		}
 	}

	else if ((strcmp(lang,"lex") == 0) ||
		 (strcmp(lang,"LEX") == 0))
	{
		QUOTE = '\"';
		salf = 1; /* don't strip leading blanks and tabs */
		previnit();
		while ((c= getcr(stdin)) != EOF)
		{
			/* the next line takes care of a double
			quote inside single quotes */
			if (c == '\'' || c == '\\' )
				backslash = ++backslash%2;
			else 
			{

			/* A quote mechanism is turned on and off here
			   also in conjunction with a backslash 
			   mechanism to avoid parsing special 
			   characters and comments imbedded 
			   within quotes.
			*/
				if(c == QUOTE)
				{
					if(backslash) backslash = 0;
					else quote = ++quote%2;
				}
				else backslash = 0;
			}
			dum = putc(c,stdout);
		}
	}

	else if ((strcmp(lang,"yacc") == 0) ||
		 (strcmp(lang,"YACC") == 0))
	{
		QUOTE = '\"';
		previnit();
		while ((c= getcr(stdin)) != EOF)
		{
			/* the next line takes care of a double
			quote inside single quotes */
			if (c == '\'' || c == '\\' )
				backslash = ++backslash%2;
			else 
			{

			/* A quote mechanism is turned on and off here
			   also in conjunction with a backslash 
			   mechanism to avoid parsing special 
			   characters and comments imbedded 
			   within quotes.
			*/
				if(c == QUOTE)
				{
					if(backslash) backslash = 0;
					else quote = ++quote%2;
				}
				else backslash = 0;
			}
			dum = putc(c,stdout);
		}
	}

	else if ((strcmp(lang,"as") == 0) ||
		(strcmp(lang,"AS") == 0 ) )
	{
		while ((c= getc(stdin)) != EOF )
		{
			if ((c == '~') && (codef == 0) &&
			    (cmntf == 0))
			{
				if((c=getc(stdin)) == '~')
				{
				    while (((c=getc(stdin)) != '\n')
					&& (c != EOF));
				    ++cmntf;
				    cmtchk();
				}
				else
				{
					++codef;
					dum = putc ('~',stdout); 
					/* write orig char */
					dum = putc (c,stdout); 
					/* write next char */
				}
			}
			else if (c == '\'') /* handle single quote */
			{
				if (backslash || quote) backslash = 0;
				else squote = ++squote%2;
				dum = putc (c,stdout);
			}
			else if (c == '\\')
			{
				dum = putc (c,stdout);
				backslash = ++backslash%2;
			}
			else if (c == '"') 
			{
				if (backslash || squote) backslash = 0;
				else quote = ++quote%2;
				dum = putc (c,stdout);
			}
			else if (c == '\n')
			{
				if (codef > 0) dum = putc (c,stdout);
				cmtchk();
			}
			else if ((c == '#') && (!quote) && 
				(!backslash) && (!squote) && (!dollar)) 
				/* strip line */
			{
				while (((c= getc(stdin)) != EOF) &&
					(c != '\n') );
				++cmntf;
				/* write end of line if not blank */
				if (codef > 0) dum = putc (c,stdout);
				cmtchk();
			}
			else
			{
				dollar = 0; /* reset dollar flag to 0 */
				if ( c == '$') dollar = 1; /* set dollar flag */
				/* dollar flag set so  not a comment */
				backslash=0;
				 ++codef;
				dum = putc (c,stdout);
			}
		}
	}
 		
	else if ((strcmp(lang,"pdpas") == 0) ||
		(strcmp(lang,"PDPAS") == 0 ) )
	{
		while ((c= getc(stdin)) != EOF )
		{
			if ((c == '~') && (codef == 0) &&
			    (cmntf == 0))
			{
				if((c=getc(stdin)) == '~')
				{
				    while (((c=getc(stdin)) != '\n')
					&& (c != EOF));
				    ++cmntf;
				    cmtchk();
				}
				else
				{
					++codef;
					dum = putc ('~',stdout); 
					/* write orig char */
					dum = putc (c,stdout); 
					/* write next char */
				}
			}
			else if (c == '\'') /* handle single quote */
			{
				if (backslash || quote) backslash = 0;
				else squote = ++squote%2;
				dum = putc (c,stdout);
			}
			else if (c == '\\')
			{
				dum = putc (c,stdout);
				backslash = ++backslash%2;
			}
			else if (c == '"') 
			{
				if (backslash || squote) backslash = 0;
				else quote = ++quote%2;
				dum = putc (c,stdout);
			}
			else if (c == '\n')
			{
				if (codef > 0) dum = putc (c,stdout);
				cmtchk();
			}
			else if ((c == '/') && (!quote) && 
				(!backslash) && (!squote) && (!dollar)) 
				/* strip line */
			{
				while (((c= getc(stdin)) != EOF) &&
					(c != '\n') );
				++cmntf;
				/* write end of line if not blank */
				if (codef > 0) dum = putc (c,stdout);
				cmtchk();
			}
			else
			{
				dollar = 0; /* reset dollar flag to 0 */
				if ( c == '$') dollar = 1; /* set dollar flag */
				/* dollar flag set so  not a comment */
				backslash=0;
				 ++codef;
				dum = putc (c,stdout);
			}
		}
	}

	else 
	{
	   dum = fprintf(stderr,
	   "LANGUAGE PARAMETER NOT A DEFINED LANGUAGE - %s\n", lang);
	   if (gflag == 0) exit(-1); /* abort if unknown lang */
	   nocomment(stdin,stdout); /* otherwise copy */
	}
	if (sflag)
	{
		if(freopen(filest,"a",stderr) == NULL)
		{
			dum = fprintf(stderr,
			"cannot open file %s for statistics\n",filest);
		}
	}
	if (cflag)
	{
		dum =  fprintf (stderr,
 "input file     lang     date        lines   cmnt  non-cmnt  both  blanks\n");
	}
	duml =  time(&tbuf);
	tim = localtime(&tbuf);
	++tim->tm_mon; /* increase month by since starts at 0 */
	/* the next lines pick up rightmost 14 bytes of filename
	for filenames over 14 characters */
	if(strlen(filein) > 14)
		for (i=0,j=(strlen(filein)-14); i<14; i++,j++)
			filein[i] = filein[j];
	dum =  fprintf (stderr,
"%-14.14s %-9s%02.2d%02.2d%02.2d-%02.2d%02.2d  %-8d%-6d%-10d%-6d%-8d\n",
filein,lang,tim->tm_year,tim->tm_mon,tim->tm_mday,tim->tm_hour,
tim->tm_min,linecnt, commentc,codec,bothc,blankc);
/* note 02.2 in obove pads left with zeros */
	return(0);
}
/***************************************************************
                LEVEL 1.6 OF ncslsub.c
 		merged by g. patton 10/22/82
**********************************************************************/

/* for 80 column input + 1 for newline character */
#define MAXLINE 256
#define BLANKOUT "                                                 \
                                "
#define BUFSIZE 512  /*physical blksize of many peripherial devices */

#define GETALINE	(dum = getaline(fp1))

#define PUTALINE(ptr)   dum = fprintf(fp2,"%s",ptr)

#define WHITESPACE(which)  ((which == ' ') || (which == '\t') || \
		(which == '\n') || (which == '\0'))

#define TERMTOK(term)  instrflg = (*(tok + strlen(tok) - 1) == term) ? 1 : 0

/*  The C and PL1 routines read a character at a time.
    The rest of the language routines read a line of code 
    (up to and including the newline character).
    Blank lines and comments are ignored and lines of 
    instructions are printed.

    _________________________________________________________________________
    |Language			Commenting Convention			     |
    |________________________	_____________________________________________|
    |									     |
    |PL1 & c & LEAP		anything within slash star, star slash       |
    |									     |
    | SHELL                     anything from a # character to end of line   |
    |                           if # is escaped or quoted its not comment    |
    |                                                                        |
    |SNOFLAKE, SPITBOL & COMP	an * in column 1.			     |
    |									     |
    |FORTRAN			a C in column 1				     |
    |									     |
    |COBOL                      an * or / in column 7 and anything between   |
    |				the program-id and environment section is    |
    |				considered a comment.			     |
    |				Note sentences and note paragraphs are also  |
    |				removed as comments.			     |
    |									     |
    |DTP			a # followed by a blank in columns 7         |
    |				and 8 and any cobol like comments.	     |
    |									     |
    |BAL			an * in column 1 or a .* in columns 1 and 2. |
    |				any text after operand to end of line.       |
    |									     |
    |SAL			any BAL or PL1 type comment.		     |
    |									     |
    |JCL                        a //* in colums 1-3. Blank lines are valid.  |
    |									     |
    |MARK4			an  aa in columns 9 and 10.		     |
    |									     |
    |M11		        any chars after a ; to end of line           |
    |									     |
    |SRT (SYNCSORT)		an  * in column 1. 	      		     |
    |									     |
    |LKE (linkage editor)	comments are anything that follows an 	     |
    |				operator and operand field.  A comment is    |
    |				continued, if there is a non-blank in col 72 |
    |			        and the last character of the operand is NOT |
    |				a comma.				     |
    |									     |
    |LR (parser generator)      comments may start in any column and must    |
    |                           be preceded by &C                            |
    |                                                                        |
    |DIRJCL (DIR/ECT JCL-	comments are an * in column 1 or the 	     |
    |kept under SCCS before	macros .LS and .BR which expand into         |
    |being expanded by		commentary lines.  .LS is the last line      |
    |preprocessors)		comment and .BR expands to a bar line of     |
    |				comprised of *s.			     |
    |									     |
    |PARMS & ERRUPDT		no comments but must process anyway.	     |
    |________________________________________________________________________|

*/

static int Prev; /* place to hold previous character */
int instrflg;
char line[MAXLINE];
char *strcpy();
char *strtok();
char *strchr();
char *fgets();

/* routine gets the next line of input up to and including the newline
that does not start with a ~~ (gath comment) or a newline(saves time here).
    Since fgets does not clear the buffer, it is cleared before an input
    operation.
*/
getaline(fp1)
register FILE *fp1;
{
	char *ret;
	dumc = 	strcpy(line,BLANKOUT);
	while( ((ret=fgets(line,MAXLINE,fp1)) != NULL) &&
	((stncmp(line,"~~",2) == 0) ||
	(line[strspn(line," \t")] == '\n')) )
		/* the last compare handles lines with only blanks */
		{
		/* check if line has only spaces or tabs */
		if (line[strspn(line," \t")] == '\n') {
			if (!salf)  /* skip count comment for blk line */
			{
				if (blankf > 0) ++blankc;
				else {
					blankf = 1;
					++blankc;
					++commentc;
				}
			}
		}
		else if (line[0] == '~') {
			++commentc;
		}
		++linecnt; /* count the line */
		dumc = 	strcpy(line,BLANKOUT);
		}
	blankf = 0;
	if (ret != NULL) ++linecnt; /* count the non blank lines */
	else line[0] = '\0'; /* null out line as flag */
	return(ret != NULL);
}


/** routine to get a line but leave blank lines
    used for JCL
*/
getbline(fp1)
register FILE *fp1;
{
	char *ret;
	dumc =  strcpy(line,BLANKOUT);
	while ( ((ret=fgets(line,MAXLINE,fp1)) != NULL) &&
		(stncmp (line,"~~",2) == 0) ) {
			++commentc;
			++linecnt;
	}
	if (line[strspn(line," \t")] == '\n') ++ blankc;
	/* above counts blank lines or car. ret, spaces, tabs */
	if (ret != NULL) ++linecnt;
	else line[0] = '\0'; /* null out line as flag */
	return(ret != NULL);
}
previnit()
{
	Prev = '\n';
}


getcr(f)
register FILE *f;
{
	extern int quote;
	register int c, prev;

	prev = Prev;
	while ((c = getch(f)) == '/')
	{
		/* make sure the comment is not imbedded in quotes */

		if ((c = getc(f)) == '*' && !quote){
			cmntf = 1; /* set comment flag */
			getcmt(f);
			Prev = prev;
		} else if (c == '/' && cplusf && !quote) {
			cmntf = 1;
			getcmt_cplus(f);
			Prev = prev;
		}
		else {
			dum = ungetc(c, f);
			c = '/';
			break;
		}
	}
	if (c != '\n' && c != EOF && c != ' ' && c != '\t') 
		{
		if ( !( (Prev == '\n') && (pl1f) ) )
			{
			codef = 1; /* set code flag if chars after comment */
			fstf = 0; /* set flag so cmtchk counts */
			}
		else
			fstf = 1; /* set flag so if next char eol no blank
				count in cmtchk */
		}
	Prev = c; /* needed so can recognize ~~ after comments */
	return(c);
}


/**
getcmt() - returns after seeing the end of comment string
(a * followed by a /) in the input.
It discards comments that its caller has detected.
*/

getcmt(f)
register FILE *f;
{
	register int c;
	/* comment flag set in caller routine */

	c = ' ';
	do {
		while (c != '*' && c != EOF) {
			if (c == '\n' )  {
				cmtchk();
				c = getc(f); /* handles blanks 
						in comment */
			}
			else {
				c = getc(f);
				cmntf = 1; /* reset comment flag */
			}
		}
		cmntf = 1; /* reset comment flag if * in first col */
	} while ((c = getc(f)) != '/' && c != EOF);
}

/**
getcmt_cplus() - similar to getcmt(), except it is for C++ style
comments that begin with //
*/

getcmt_cplus(f)
register FILE *f;
{
	register int c;
	
	while ( (c = getc(f)) != '\n' && c != EOF)
	{
		/* do nothing */
	}
	(void) ungetc(c, f);
}

/**
getch(f) - gets a character
discards blank lines
*/

getch(f)
register FILE *f;
{
	register int c;

	if (Prev != '\n') {
		c = getc(f);
		if (c == '\n' )  cmtchk();
		Prev = c;
	}

	else
		/* code to handle first characters */
	{
		c = getc (f);
		while (( c == '~' || c == '\n' ||
			( ( (c == ' ' ) || ( c == '\t') ) && ( ! salf)) ) &&
			Prev == '\n')
		{
			if (c == '~')
			{
				if((c = getc(f)) == '~')
					{
					c = chkgath(f);
					}
				else
					{
					dum = ungetc(c,f);
					c = '~';
					Prev = c;
					break;
					}
			}
			while (((c == ' ' || c == '\t') && ( ! salf )) ||
				(c == '\n')) 
				{
				if (c == '\n' ) cmtchk();
				Prev = c;
				c = getc(f);
				}
		}
	}
	return(c);
}

chkgath(f)
register FILE *f;
{
	register int c;
	while (( c = getc(f) ) != '\n');
	Prev = c; /* set Prev to eol when appropriate */
	c = getc(f);
	++commentc; /* cnt gath comm as a line of comm */
	++linecnt;
	return(c);
}
snobolcomment(fp1,fp2)
register FILE *fp1, *fp2;
{
	int whitecnt;

	/* reads a line of code (up to and including the newline) */
	while GETALINE
	{
		if (line[0] != '*')
		{
			++codec;
			whitecnt = strspn(line," \t\n");
			PUTALINE(line+whitecnt);
		}
		else
			++commentc; /* line is a comment */
	}
}

fortrancomment(fp1,fp2)
register FILE *fp1, *fp2;
{
	int whitecnt;

	/* reads a line of code (up to and including the newline) */
	while GETALINE
	{
		if ((line[0] != 'c') && (line[0] != 'C'))
		{
			++codec; /* line is code */
			whitecnt = strspn(line," \t\n");
			PUTALINE(line+whitecnt);
		}
		else
			++commentc; /* line is a comment */
	}
}
cobolcomment(fp1,fp2)
register FILE *fp1, *fp2;
{
    int n;
    line[0] = ' '; /* put in initial blank since prev could be blank */
    while (line[0] != '\0')
    {

	while ( GETALINE  && (stncmp(&line[7],"program-id",10) != 0))
	{
		/* get rid of beginning comments */
		if((line[6] != '*') && (line[6] != '/')) {
			++codec;
			PUTALINE(line + (strspn(line," \t\n")));
		}
		else
			++commentc; /* line is a comment */
	}

	/* print program id line */
	if (line[0] == '\0') break; /* we have come to end of file */
	++codec;
	PUTALINE(line + (strspn(line," \t\n")));

	/* ignore commentary in identification divison */
	while ( GETALINE  && 
      ( (stncmp(line+7,"environment ",12) != 0)  &&
      (stncmp(line+19 + (strspn(line+19," \t")),"division",8) != 0) ) )
		++commentc;

	/* print environment division line */
	if (line[0] == '\0') break; /* we have come to end of file */
	++codec;
	PUTALINE(line + (strspn(line," \t\n")));

	while ( GETALINE  && 
      ( (stncmp(&line[7],"procedure ",10) != 0) &&
      (stncmp(line+17 + (strspn(line+17," \t")),"division",8) != 0) ) )
	{
		/* get rid of environment division comments */
		if((line[6] != '*') && (line[6] != '/')) {
			++codec;
			PUTALINE(line + (strspn(line," \t\n")));
		}
		else
			++commentc;
	}

	/* print procedure division line */
	if (line[0] == '\0') break; /* we have come to end of file */
	++codec;
	PUTALINE(line + (strspn(line," \t\n")));

	/* now I must look for regular type comments and procedural
	   note comments.
	*/
	while GETALINE
	{
		if ((line[6] == '*') || (line[6] == '/'))  {
			++commentc;
			continue;
		}

		/* check if label line and if there is a label
		   check if note is on same line.
		   */
		if ( ! WHITESPACE(line[7]) )
			labntck(fp1,fp2);
		else 
		{
			n = strspn(line," \t\n");
			if ((stncmp(line+n,"note",4) != 0) &&
			   (stncmp(line+n,"NOTE",4) != 0))
			{	
				/* not a note , turn label off */
				instrflg = 0;
				++codec;
				PUTALINE(line + n);
			}
			else
			{
				/* is a note, check if paragraph note
				   or line note */
				if(instrflg)
				{
					instrflg = 0;
					++commentc;
					parnote(fp1,fp2);
				}
				/* removes the line note.
				   returns to get the next
				   line after the note.
				   */
				else linenote(fp1);
			}
		}
	}

    }
}

/** subroutine to ignore commentary lines in a cobol note paragraph. 
	this is any lines that exist before the next label.
	*/
parnote(fp1,fp2)
register FILE *fp1, *fp2;
{
	while ( GETALINE  && ( WHITESPACE(line[7]) ) )
		++commentc; /* get rid of comments in while loop */
		/* check if notes are recursively defined one
		after the other
		*/

	/* if end of file don't go on and skip labntck */
	if (line[0] != '\0') labntck(fp1,fp2);
}

/* subroutine to check if line is a label and check if the note
	is in the labeled paragraph.
	*/
labntck(fp1,fp2)
register FILE *fp1,*fp2;
{
	char *tok;
	char holdline[MAXLINE];
	dumc =  strcpy(holdline,line);
	tok = strtok(&holdline[7]," \t\n");
	TERMTOK('.');
	tok = strtok((char *)0," \t\n");
	if (tok != NULL)
	{
		if ((stncmp(tok,"note",4) == 0) ||
		   (stncmp(tok,"NOTE",4) == 0))
		{
			instrflg = 0;
			++commentc; /* cnt note before get next line */
			parnote(fp1,fp2);
		}
		else

		/* label is not for note ; turn label off */
		{
			instrflg = 0;
			++codec;
			PUTALINE(line + (strspn(line," \t\n")));
		}
	}
	else
		/* print label , label might still be for 
		   a note , so it stays set
		   */
	{
		++codec;
		PUTALINE(line + (strspn(line," \t\n")));
	}

}

/** subroutine for ignoring note lines from cobol programs */
linenote(fp1)
register FILE *fp1;
{
	/* delete everything up to and including the note
	   terminator ( a period ). 
	   possibly scanning across several input lines */

	while ((strchr(line,'.') == NULL)  &&
		(line[0] != '\0') ){
		++commentc; /* count note lines as comments */
		GETALINE;
	}
	/* get out if eof or count line with period */
	if (line[0] != '\0') ++commentc;

}

dtpcomment(fp1,fp2)
register FILE *fp1, *fp2;
{

	while GETALINE
	{
		if((stncmp(&line[6],"# ",2)  != 0)  && 
		   (stncmp(&line[6],"#\t",2) != 0)  && 
		   (stncmp(&line[6],"#\n",2) != 0))
		{
			PUTALINE(line);
			++codec;
		}
		else
			++commentc;
	dumc = 	strcpy(line,BLANKOUT);
	}
}

jclcomment(fp1,fp2)
register FILE *fp1, *fp2;
{

	while  (getbline(fp1))
	{

		/*
		use getbline since jcl data may have valid leading
		whitespace or blank lines in input data
		*/

		if (stncmp(line,"//*",3) != 0)
		{
			++codec;
			PUTALINE(line);
		}
		else
			++commentc; /* line is a comment */
	}
}

dirjclcomment(fp1,fp2)
register FILE *fp1, *fp2;
{

	while  GETALINE
	{

		/*
		    jcl will not have leading whitespace nor
		    blank lines, so no checking is done.
		*/

		if ((stncmp(line,".BR",3) != 0)  &&
		    (stncmp(line,".LS",3) != 0)  &&
		    (stncmp(line,"*",1) != 0))
		{
			++codec; /* line is not comment */
			PUTALINE(line + (strspn(line," \t\n")));
		}
		else
			++commentc;
	}
}

mark4comment(fp1,fp2)
register FILE *fp1, *fp2;
{

	while GETALINE
	{
		if((stncmp(&line[8],"aa",2) != 0) &&
		   (stncmp(&line[8],"AA",2) != 0))
		{
			++codec; /* line is a comment */
			PUTALINE(line + (strspn(line," \t\n")));
		}
		else
			++commentc;
	}
}

balcomment(fp1,fp2)
register FILE *fp1, *fp2;
{
	char *p; /* pointer used for parsing string */
	char *strpbrk();
	int strspn();

	while GETALINE
	{
		p = line;
		if ((line[0] == '*') || (stncmp(line,".*",2) == 0))
			++commentc; /* line is a comment */
		else if ( ! (WHITESPACE(line[0]))) {
			++codec;
			while (1)
			{
			p = strpbrk(p," \t\n"); /* skip lable */
			if (*p == '\n') break; /* only a lable */
			p = p + strspn(p," \t"); /* skip blanks */
			p = strpbrk(p," \t\n"); /* strip operator */
			p = p + strspn(p," \t"); /* strip blanks */
			p = strpbrk(p," \t\n"); /* strip operand */
			if (*p == '\n') break; /* no comments */
			p = p + strspn(p," \t"); /* skip blanks */
			if (*p == '\n') break;
			++commentc;
			++bothc;
			dumc =  strcpy(p,"\n"); /* force end of 
						line here */
			break;
			}
			PUTALINE(line + (strspn(line," \t\n")));
		}
		else {
			while (1)
			{
			p = p + strspn(p," \t"); /* strip blanks */
			if(*p == '\n')
			{
				++commentc;
				++blankc;
				break;
			}
			p = strpbrk(p," \t\n"); /* skip operator */
			++codec;
			if(*p == '\n') break; /* only operator */
			p = p + strspn(p," \t"); /* skip blanks */
			p = strpbrk(p," \t\n"); /* skip operand */
			if (*p == '\n') break; /* no comments */
			p = p + strspn(p," \t"); /* skip blanks */
			if (*p == '\n') break;
			++commentc;
			++bothc;
			dumc =  strcpy(p,"\n"); /* force end of 
						line here */
			break;
			}
			PUTALINE(line + (strspn(line," \t\n")));
		}
	}
}

lkecomment(fp1,fp2)
register FILE *fp1, *fp2;
{
	char *tok;

	/* format of an instruction is:
		operator - col 2
		operand  - preceded by one or more blanks
		remarks  - optional, preceded by one or more blanks.

	   to continue an instruction, a non blank must be coded in 
	   col. 72 AND a comma must be the last character in the operand.
	   to continue a comment, a non blank must be coded in col. 72.
	   All continued statements or comments start in column 16.
	   There is no limit on continuation cards.

	   So a comment will be deleted, if column 72 is non-blank and
	   the last character of the operand is NOT a comma.
	*/


	while GETALINE
	{
		++codec; /* count a non comment */
		PUTALINE(line + (strspn(line," \t\n")));

		/* determine if instr or comment continue
		retrieve the operand token and check out
		the last character
		*/
		tok = strtok(&line[1]," \t\n");
		tok = strtok((char *)0," \t\n");
		if (strlen (tok) > 0 ) TERMTOK(',');
		/* does the line also have a continuation */
		if ( ! WHITESPACE(line[71]) )
		{
			line[71] = '\n'; /* reset eol */
			tok = strtok ((char *) 0, " \t\n");
			if (tok != NULL) {
				++commentc; /* comment on line too */
				++bothc; /* therefore both on line */
			}
			getcontin(fp1,fp2);
		}
		else {
			tok = strtok ((char *)0," \t\n");
			if (tok != NULL){
				++commentc; /* comment on line too */
				++bothc; /* therefore a both line */
			}
		}
	}
}

/** this routine retrieves the continuation lines of an instruction
   or comment.  Instructions are printed and comments thrown out
*/
getcontin(fp1,fp2)
register FILE *fp1, *fp2;
{
	char *tok;

	while ( GETALINE  && !(WHITESPACE(line[71])))
	{
		if (instrflg)
		{
			++codec; /* it was code that was continued */
			PUTALINE(line + (strspn(line," \t\n")));
			tok = strtok(&line[15]," \t\n");
			TERMTOK(',');
			line[71] = '\n'; /* reset end of line */
			tok = strtok ((char *) 0," \t\n");
			if (tok != NULL) {
				++commentc; /* comment on end */
				++bothc; /* code and comment on line */
			}
		}
		else
			++commentc; 
	}
	if  ( instrflg )
	{
		++codec; /* this is a line of code at least */
		PUTALINE(line + (strspn(line," \t\n")));
		tok = strtok(&line[15]," \t\n");
		TERMTOK(',');
		tok = strtok ((char*) 0," \t\n"); /* see what else 
						  on line */
		if (tok != NULL) {
			++commentc; /* comment on last card */
			++bothc; /* also code on last card */
		}
	}
	else
		++commentc; /* only comment on last card */
}

lrcomment (fp1,fp2)
register FILE *fp1, *fp2;
{
	while GETALINE
	{
		if(stncmp(line + strspn(line," \t\n"),"&C",2) != 0)
		{
			++codec;
			PUTALINE(line + (strspn(line," \t\n")));
		}
		else ++commentc;
	}
}
nocomment(fp1,fp2)
register FILE *fp1, *fp2;
{

	/* copy input to output removing leading whitespace*/
	while (getbline(fp1))
	{
		++codec; /* count code lines */
		PUTALINE(line + (strspn(line," \t")));
	}
}
cmtchk()
{
	/*
	this routine is used to count comments and language statements
	lines with comments and non comments are counted as bothc.
	The variables used here cmntf, commentc, codef, fstf, codec
	blankf, blankc and linecnt are defined globally in the main
	routine.  fstf is set in getcr.
	This routine is entered on end of line or EOF
	*/

	if (cmntf > 0 || (fstf && !(Prev == '\n') ) ) {
		++commentc;
		blankf = 0;
	}
	if (codef > 0) {
		++codec;
		blankf = 0;
	}
	if (cmntf == 0 && codef == 0 &&
	   ( !fstf || (fstf && Prev == '\n') ) ) {
		if (blankf > 0) ++blankc;
		else {
			blankf = 1;
			++blankc;
			++commentc; /* one blank counted as comment */
		}
	}
	if (cmntf > 0 && codef > 0) ++bothc;
	cmntf = 0;
	codef = 0;
	++linecnt;
}
/*	@(#)getopt.c	1.2	*/

#define ERR(s, c)	if(opterr){\
	dum = fputs(argv[0], stderr);\
	dum = fputs(s, stderr);\
	dum = putc(c, stderr);\
	dum = putc('\n', stderr);}

extern int strcmp();
extern char *strchr();

int	opterr = 1;
int	optind = 1;
int	optopt;

#ifndef __alpha
int
getopt(argc, argv, opts)
int	argc;
char	**argv, *opts;
{
	static int sp = 1;
	register int c;
	register char *cp;

	if(sp == 1)
		if(optind >= argc ||
		   argv[optind][0] != '-' || argv[optind][1] == '\0')
			return(EOF);
		else if(strcmp(argv[optind], "--") == NULL) {
			optind++;
			return(EOF);
		}
	optopt = c = argv[optind][sp];
	if(c == ':' || (cp=strchr(opts, c)) == NULL) {
		ERR(": illegal option -- ", c);
		if(argv[optind][++sp] == '\0') {
			optind++;
			sp = 1;
		}
		return('?');
	}
	if(*++cp == ':') {
		if(argv[optind][sp+1] != '\0')
			optarg = &argv[optind++][sp+1];
		else if(++optind >= argc) {
			ERR(": option requires an argument -- ", c);
			sp = 1;
			return('?');
		} else
			optarg = argv[optind++];
		sp = 1;
	} else {
		if(argv[optind][++sp] == '\0') {
			sp = 1;
			optind++;
		}
		optarg = NULL;
	}
	return(c);
}
#endif

/*
 * strncmp 
 * redefined as stncmp because hp can have only 5 char unique names
 * and strnc would be a dupelicate with other string functions.
 * Compare strings (at most n bytes)
 *	returns: s1>s2; >0  s1==s2; 0  s1<s2; <0
 */

int
stncmp(s1, s2, n)
register char *s1, *s2;
register n;
{
	if(s1 == s2)
		return(0);
	while(--n >= 0 && *s1 == *s2++)
		if(*s1++ == '\0')
			return(0);
	return((n < 0)? 0: (*s1 - *--s2));
}
#if IBM370
/*	@(#)strtok.c	1.2	*/

/*
 * strtok 
 * uses strpbrk and strspn to break string into tokens on
 * sequentially subsequent calls.  returns NULL when no
 * non-separator characters remain.
 * `subsequent' calls are calls with first argument NULL.
 */

#define	GNULL	(char*)0


int strspn();
char *strpbrk();
char *
strtok(string, sepset)
char	*string, *sepset;
{
	register char	*p, *q, *r;
	static char	*savept;

	/*first or subsequent call*/
	p = (string == GNULL)? savept: string;

	if(p == 0)		/* return if no tokens remaining */
		return(GNULL);

	q = p + strspn(p, sepset);	/* skip leading separators */

	if(*q == '\0')		/* return if no tokens remaining */
		return(GNULL);

	if((r = strpbrk(q, sepset)) == GNULL)	/* move past token */
		savept = 0;	/* indicate this is last token */
	else {
		*r = '\0';
		savept = ++r;
	}
	return(q);
}
/*
 * strpbrk 
 *  Return ptr to first occurance of any character from `brkset'
 *  in the character string `string'; NULL if none exists. 
 */
char *
strpbrk(string, brkset)
register char *string, *brkset;
{
		register char *p;
	
		if(!string || !brkset)
			return(0);
		do {
		    for(p=brkset; *p != '\0' && *p != *string; ++p) ;
		    if(*p != '\0')
			return(string);
		}
		while(*string++);
		return(0);
}
#else
/* for non IBM the string routines should not be needed */
#endif

/*  Routine to give the time needed by ncsl and
    ncsldiff.     Execution of localtime(t) will 
    populate the tm structure.  
*/
#define	dysize(A) (((A)%4)? 365: 366)
/*	@(#)time.h	1.2	*/

long	timezone = 5*60*60; /* set for eastern standard time */



static int dmsize[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


/*
struct tm *
localtime(timl)
long	*timl;
{
	long copyt;
	copyt = *timl - timezone;
	tim = gmtime(&copyt);
}
*/
struct tm *
gmtime(timl)
long	*timl;
{
	register int d0, d1;
	long hms, day;
	static struct tm xtime;

	/*
	 * break initial number into days
	 */
	hms = *timl % 86400L;
	day = *timl / 86400L;
	if(hms < 0) {
		hms += 86400L;
		day -= 1;
	}
	/*
	 * generate hours:minutes:seconds
	 */
	xtime.tm_sec = hms % 60;
	d1 = hms / 60;
	xtime.tm_min = d1 % 60;
	d1 /= 60;
	xtime.tm_hour = d1;

	/*
	 * day is the day number.
	 * generate day of the week.
	 * The addend is 4 mod 7 (1/1/1970 was Thursday)
	 */

	xtime.tm_wday = (day + 7340036L) % 7;

	/*
	 * year number
	 */
	if(day >= 0)
		for(d1=70; day >= dysize(d1); d1++)
			day -= dysize(d1);
	else
		for(d1=70; day < 0; d1--)
			day += dysize(d1-1);
	xtime.tm_year = d1;
	xtime.tm_yday = d0 = day;

	/*
	 * generate month
	 */

	if(dysize(d1) == 366)
		dmsize[1] = 29;
	for(d1=0; d0 >= dmsize[d1]; d1++)
		d0 -= dmsize[d1];
	dmsize[1] = 28;
	xtime.tm_mday = d0+1;
	xtime.tm_mon = d1;
	xtime.tm_isdst = 0;
	return(&xtime);
}

