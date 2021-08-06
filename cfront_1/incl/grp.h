/* @(#) grp.h 1.5 2/16/87 11:02:12 */
/*ident	"@(#)cfront:incl/grp.h	1.5"*/

#ifndef GRPH
#define GRPH

#ifndef FILE
#       include <stdio.h>
#endif

struct	group {	/* see getgrent(3) */
	char	*gr_name;
	char	*gr_passwd;
	int	gr_gid;
	char	**gr_mem;
};

extern void endgrent ();
extern group *fgetgrent (FILE*);
extern group *getgrent ();
extern group *getgrgid (int);
extern group *getgrnam (const char*);
extern void setgrent ();

#endif
