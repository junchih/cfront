/* @(#) pwd.h 1.5 2/16/87 11:02:27 */
/*ident	"@(#)cfront:incl/pwd.h	1.5"*/

#ifndef PWDH
#define PWDH

#ifndef FILE
#       include <stdio.h>
#endif

struct passwd {
	char	*pw_name;
	char	*pw_passwd;
	int	pw_uid;
	int	pw_gid;
	char	*pw_age;
	char	*pw_comment;
	char	*pw_gecos;
	char	*pw_dir;
	char	*pw_shell;
};

struct comment {
	char	*c_dept;
	char	*c_name;
	char	*c_acct;
	char	*c_bin;
};

extern passwd *getpwent ();
extern passwd *getpwuid ();
extern passwd *getpwnam (const char*);
extern passwd *fgetpwent (FILE*);

extern void setpwent ();
extern void endpwent ();
extern int putpwent (const passwd*, FILE*);

#endif

