/* @(#) ftw.h 1.4 2/16/87 11:02:07 */
/*ident	"@(#)cfront:incl/ftw.h	1.4"*/

#ifndef FTWH
#define FTWH

/*
 *	Codes for the third argument to the user-supplied function
 *	which is passed as the second argument to ftw
 */

#define	FTW_F	0	/* file */
#define	FTW_D	1	/* directory */
#define	FTW_DNR	2	/* directory without read permission */
#define	FTW_NS	3	/* unknown type, stat failed */

#ifndef PFSEEN
#define PFSEEN
typedef int (*PF) ();
#endif

extern int ftw (const char*, PF, int);

#endif
