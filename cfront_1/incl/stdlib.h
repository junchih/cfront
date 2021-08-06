/* @(#) stdlib.h 1.6 2/16/87 11:02:32 */
/*ident	"@(#)cfront:incl/stdlib.h	1.6"*/


#ifndef STDLIBH
#define STDLIBH

extern int     abort();
extern double  atof (const char*);
extern int     atoi (const char*);
extern long    atol (const char*);
extern char*   calloc (unsigned,unsigned);
extern void    exit (int);
extern void    free (char*);
extern char*   getenv (const char*);
extern char*   malloc (unsigned);
extern int     rand ();
extern char*   realloc (char*, unsigned);
extern void    srand  (unsigned);
extern double  strtod (const char*, char**);
extern long    strtol (const char*, char**, int);
extern int     system (const char*);

#endif
