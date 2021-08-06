/* @(#) ustat.h 1.3 2/16/87 11:02:42 */
/*ident	"@(#)cfront:incl/ustat.h	1.3"*/

#ifndef USTATH
#define USTATH

/* <sys/types.h> must be included    */

struct  ustat {
	daddr_t	f_tfree;	/* total free */
	ino_t	f_tinode;	/* total inodes free */
	char	f_fname[6];	/* filsys name */
	char	f_fpack[6];	/* filsys pack name */
};

extern int ustat(int, ustat*);

#endif
