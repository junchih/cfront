/* @(#) utsname.h 1.3 2/16/87 11:02:39 */
/*ident	"@(#)cfront:incl/sys/utsname.h	1.3"*/
struct utsname {
	char	sysname[9];
	char	nodename[9];
	char	release[9];
	char	version[9];
	char	machine[9];
};

extern int uname (utsname*);
