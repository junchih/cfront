/******************************************************************************* 
C++ source for the C++ Language System, Release 3.0.  This product
is a new release of the original cfront developed in the computer
science research center of AT&T Bell Laboratories.

Copyright (c) 1991 AT&T and UNIX System Laboratories, Inc.
Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.

THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
Laboratories, Inc.  The copyright notice above does not evidence
any actual or intended publication of such source code.

*******************************************************************************//*
 *      This is a handmade version of unistd.h
 *      for the Sun 4 running Solaris 2.0.
 */

#ifndef __UNISTD_H
#define __UNISTD_H

#ifndef __TYPES_H
#include <sys/types.h>
#endif



#define exit ______exit
#define rename ______rename
#define acct ______acct
#define brk ______brk
#define chroot ______chroot
#define fchroot ______fchroot
#define fattach ______fattach
#define fchdir ______fchdir
#define fchown ______fchown
#define fdetach ______fdetach
#define fsync ______fsync
#define ftruncate ______ftruncate
#define getpgid ______getpgid
#define gettxt ______gettxt
#define getsid ______getsid
#define ioctl ______ioctl
#define lchown ______lchown
#define mincore ______mincore
#define nice ______nice
#define profil ______profil
#define ptrace ______ptrace
#define readlink ______readlink
#define sbrk ______sbrk
#define setgroups ______setgroups
#define setpgrp ______setpgrp
#define stime ______stime
#define symlink ______symlink
#define sync ______sync
#define truncate ______truncate
#define vfork ______vfork
#define vhangup ______vhangup



#define _exit _______exit
#define access ______access
#define alarm ______alarm
#define chdir ______chdir
#define chmod ______chmod
#define chown ______chown
#define close ______close
#define ctermid ______ctermid
#define cuserid ______cuserid
#define dup ______dup
#define dup2 ______dup2
#define execl ______execl
#define execle ______execle
#define execlp ______execlp
#define execv ______execv
#define execve ______execve
#define execvp ______execvp
#define fork ______fork
#define fork1 ______fork1
#define fpathconf ______fpathconf
#define getcwd ______getcwd
#define getegid ______getegid
#define geteuid ______geteuid
#define getgid ______getgid
#define getgroups ______getgroups
#define getlogin ______getlogin
#define getlogin_r ______getlogin_r
#define getpgrp ______getpgrp
#define getpid ______getpid
#define getppid ______getppid
#define getuid ______getuid
#define isatty ______isatty
#define link ______link
#define lockf ______lockf
#define lseek ______lseek
#define pathconf ______pathconf
#define pause ______pause
#define pipe ______pipe
#define read ______read
#define rmdir ______rmdir
#define setgid ______setgid
#define setegid ______setegid
#define setpgid ______setpgid
#define setsid ______setsid
#define setuid ______setuid
#define seteuid ______seteuid
#define sleep ______sleep
#define sysconf ______sysconf
#define tcgetpgrp ______tcgetpgrp
#define tcsetpgrp ______tcsetpgrp
#define ttyname ______ttyname
#define ttyname_r ______ttyname_r
#define unlink ______unlink
#define write ______write

/*	Copyright (c) 1988 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#ifndef _UNISTD_H
#define	_UNISTD_H

#pragma ident	"@(#)unistd.h	1.2	90/03/30 SMI"	/* SVr4.0 1.26	*/

#include <sys/types.h>
#include <sys/unistd.h>

#ifdef	__cplusplusSUN
extern "C" {
#endif

/* Symbolic constants for the "access" routine: */
#define	R_OK	4	/* Test for Read permission */
#define	W_OK	2	/* Test for Write permission */
#define	X_OK	1	/* Test for eXecute permission */
#define	F_OK	0	/* Test for existence of File */

#if !defined(_POSIX_SOURCE)
#define	F_ULOCK	0	/* Unlock a previously locked region */
#define	F_LOCK	1	/* Lock a region for exclusive use */
#define	F_TLOCK	2	/* Test and lock a region for exclusive use */
#define	F_TEST	3	/* Test a region for other processes locks */
#endif /* !defined(_POSIX_SOURCE) */


/* Symbolic constants for the "lseek" routine: */
#define	SEEK_SET	0	/* Set file pointer to "offset" */
#define	SEEK_CUR	1	/* Set file pointer to current plus "offset" */
#define	SEEK_END	2	/* Set file pointer to EOF plus "offset" */

#if !defined(_POSIX_SOURCE)
/* Path names: */
#define	GF_PATH	"/etc/group"	/* Path name of the "group" file */
#define	PF_PATH	"/etc/passwd"	/* Path name of the "passwd" file */
#endif /* !defined(_POSIX_SOURCE) */

/* compile-time symbolic constants,
 * Support does not mean the feature is enabled.
 * Use pathconf/sysconf to obtain actual configuration value.
 *
 */
#define	_POSIX_JOB_CONTROL	1
#define	_POSIX_SAVED_IDS	1

#ifndef _POSIX_VDISABLE
#define	_POSIX_VDISABLE		0
#endif

#ifndef	NULL
#define	NULL	0
#endif

#define	STDIN_FILENO	0
#define	STDOUT_FILENO	1
#define	STDERR_FILENO	2

#if defined(__STDC__)

extern int access(const char *, int);
#if !defined(_POSIX_SOURCE)
extern int acct(const char *);
#endif /* !defined(_POSIX_SOURCE) */
extern unsigned alarm(unsigned);
#if !defined(_POSIX_SOURCE)
extern int brk(void *);
#endif /* !defined(_POSIX_SOURCE) */
extern int chdir(const char *);
extern int chown(const char *, uid_t, gid_t);
#if !defined(_POSIX_SOURCE)
extern int chroot(const char *);
#endif /* !defined(_POSIX_SOURCE) */
extern int close(int);
extern char *ctermid(char *);
extern char *cuserid(char *);
extern int dup(int);
extern int dup2(int, int);
extern int execl(const char *, const char *, ...);
extern int execle(const char *, const char *, ...);
extern int execlp(const char *, const char *, ...);
extern int execv(const char *, char *const *);
extern int execve(const char *, char *const *, char *const *);
extern int execvp(const char *, char *const *);
extern void exit(int);
extern void _exit(int);
#if !defined(_POSIX_SOURCE)
extern int fattach(int, const char *);
extern int fchdir(int);
extern int fchown(int, uid_t, gid_t);
extern int fchroot(int);
extern int fdetach(const char *);
#endif /* !defined(_POSIX_SOURCE) */
extern pid_t fork(void);
extern long fpathconf(int, int);
#if !defined(_POSIX_SOURCE)
extern int fsync(int);
extern int ftruncate(int, off_t);
#endif /* !defined(_POSIX_SOURCE) */
extern char *getcwd(char *, size_t);
extern gid_t getegid(void);
extern uid_t geteuid(void);
extern gid_t getgid(void);
extern int getgroups(int, gid_t *);
extern char *getlogin(void);
#if !defined(_POSIX_SOURCE)
extern pid_t getpgid(pid_t);
#endif /* !defined(_POSIX_SOURCE) */
extern pid_t getpid(void);
extern pid_t getppid(void);
extern pid_t getpgrp(void);
#if !defined(_POSIX_SOURCE)
char *gettxt(const char *, const char *);
#endif /* !defined(_POSIX_SOURCE) */
#if !defined(_POSIX_SOURCE)
extern pid_t getsid(pid_t);
#endif /* !defined(_POSIX_SOURCE) */
extern uid_t getuid(void);
#if !defined(_POSIX_SOURCE)
extern int ioctl(int, int, ...);
#endif /* !defined(_POSIX_SOURCE) */
extern int isatty(int);
extern int link(const char *, const char *);
#if !defined(_POSIX_SOURCE)
extern int lchown(const char *, uid_t, gid_t);
extern int lockf(int, int, long);
#endif /* !defined(_POSIX_SOURCE) */
extern off_t lseek(int, off_t, int);
#if !defined(_POSIX_SOURCE)
extern int mincore(caddr_t, size_t, char *);
extern int nice(int);
#endif /* !defined(_POSIX_SOURCE) */
extern long pathconf(const char *, int);
extern int pause(void);
extern int pipe(int *);
#if !defined(_POSIX_SOURCE)
extern void profil(unsigned short *, unsigned int, unsigned int, unsigned int);
extern int ptrace(int, pid_t, int, int);
#endif /* !defined(_POSIX_SOURCE) */
extern ssize_t read(int, void *, unsigned);
#if !defined(_POSIX_SOURCE)
extern int readlink(const char *, void *, int);
#endif /* !defined(_POSIX_SOURCE) */
extern int rename(const char *, const char *);
extern int rmdir(const char *);
#if !defined(_POSIX_SOURCE)
extern void *sbrk(int);
#endif /* !defined(_POSIX_SOURCE) */
extern int setgid(gid_t);
#if !defined(_POSIX_SOURCE)
extern int setegid(gid_t);
#endif /* !defined(_POSIX_SOURCE) */
#if !defined(_POSIX_SOURCE)
extern int setgroups(int, const gid_t *);
#endif /* !defined(_POSIX_SOURCE) */
extern int setpgid(pid_t, pid_t);
#if !defined(_POSIX_SOURCE)
extern pid_t setpgrp(void);
#endif /* !defined(_POSIX_SOURCE) */
extern pid_t setsid(void);
extern int setuid(uid_t);
#if !defined(_POSIX_SOURCE)
extern int seteuid(uid_t);
#endif /* !defined(_POSIX_SOURCE) */
extern unsigned sleep(unsigned);
#if !defined(_POSIX_SOURCE)
extern int stime(const time_t *);
extern int symlink(const char *, const char *);
extern void sync(void);
#endif /* !defined(_POSIX_SOURCE) */
extern long sysconf(int);
extern pid_t tcgetpgrp(int);
extern int tcsetpgrp(int, pid_t);
#if !defined(_POSIX_SOURCE)
extern int truncate(const char *, off_t);
#endif /* !defined(_POSIX_SOURCE) */
extern char *ttyname(int);
extern int unlink(const char *);
#if !defined(_POSIX_SOURCE)
extern pid_t vfork(void);
extern void vhangup(void);
#endif /* !defined(_POSIX_SOURCE) */
extern ssize_t write(int, const void *, unsigned);

#else

extern int access();
#if !defined(_POSIX_SOURCE)
extern int acct();
#endif /* !defined(_POSIX_SOURCE) */
extern unsigned alarm();
#if !defined(_POSIX_SOURCE)
extern int brk();
#endif /* !defined(_POSIX_SOURCE) */
extern int chdir();
extern int chown();
#if !defined(_POSIX_SOURCE)
extern int chroot();
#endif /* !defined(_POSIX_SOURCE) */
extern int close();
extern char *ctermid();
extern char *cuserid();
extern int dup();
extern int dup2();
extern int execl();
extern int execle();
extern int execlp();
extern int execv();
extern int execve();
extern int execvp();
extern void exit();
extern void _exit();
#if !defined(_POSIX_SOURCE)
extern int fattach();
extern int fchdir();
extern int fchown();
extern int fchroot();
extern int fdetach();
#endif /* !defined(_POSIX_SOURCE) */
extern int fork();
extern long fpathconf();
#if !defined(_POSIX_SOURCE)
extern int fsync();
extern int ftruncate();
#endif /* !defined(_POSIX_SOURCE) */
extern char *getcwd();
extern int getegid();
extern int geteuid();
extern int getgid();
extern int getgroups();
extern char *getlogin();
#if !defined(_POSIX_SOURCE)
extern int getpgid();
#endif /* !defined(_POSIX_SOURCE) */
extern int getpid();
extern int getppid();
extern int getpgrp();
#if !defined(_POSIX_SOURCE)
extern int getsid();
#endif /* !defined(_POSIX_SOURCE) */
#if !defined(_POSIX_SOURCE)
char *gettxt();
#endif /* !defined(_POSIX_SOURCE) */
extern int getuid();
#if !defined(_POSIX_SOURCE)
extern int ioctl();
#endif /* !defined(_POSIX_SOURCE) */
extern int isatty();
#if !defined(_POSIX_SOURCE)
extern int lchown();
#endif /* !defined(_POSIX_SOURCE) */
extern int link();
#if !defined(_POSIX_SOURCE)
extern int lockf();
#endif /* !defined(_POSIX_SOURCE) */
extern long lseek();
#if !defined(_POSIX_SOURCE)
extern int mincore();
extern int nice();
#endif /* !defined(_POSIX_SOURCE) */
extern long pathconf();
extern int pause();
extern int pipe();
#if !defined(_POSIX_SOURCE)
extern void profil();
extern int ptrace();
#endif /* !defined(_POSIX_SOURCE) */
extern ssize_t read();
#if !defined(_POSIX_SOURCE)
extern int readlink();
#endif /* !defined(_POSIX_SOURCE) */
extern int rmdir();
#if !defined(_POSIX_SOURCE)
extern void *sbrk();
#endif /* !defined(_POSIX_SOURCE) */
extern int setgid();
#if !defined(_POSIX_SOURCE)
extern int setegid();
#endif /* !defined(_POSIX_SOURCE) */
#if !defined(_POSIX_SOURCE)
extern int setgroups();
#endif /* !defined(_POSIX_SOURCE) */
extern int setpgid();
#if !defined(_POSIX_SOURCE)
extern int setpgrp();
#endif /* !defined(_POSIX_SOURCE) */
extern int setsid();
extern int setuid();
#if !defined(_POSIX_SOURCE)
extern int seteuid();
#endif /* !defined(_POSIX_SOURCE) */
extern unsigned sleep();
#if !defined(_POSIX_SOURCE)
extern int stime();
extern int symlink();
extern void sync();
#endif /* !defined(_POSIX_SOURCE) */
extern long sysconf();
extern int tcgetpgrp();
extern int tcsetpgrp();
#if !defined(_POSIX_SOURCE)
extern int truncate();
#endif /* !defined(_POSIX_SOURCE) */
extern char *ttyname();
extern int unlink();
#if !defined(_POSIX_SOURCE)
extern int vfork();
extern void vhangup();
#endif /* !defined(_POSIX_SOURCE) */
extern ssize_t write();

#endif

#ifdef	__cplusplusSUN
}
#endif

#endif /* _UNISTD_H */
 

#undef pathconf
#undef execvp
#undef cuserid
#undef lchown
#undef setsid
#undef setpgid
#undef profil
#undef fpathconf
#undef setuid
#undef seteuid
#undef setgroups
#undef write
#undef chroot
#undef fchroot
#undef unlink
#undef getlogin
#undef getlogin_r
#undef getpgrp
#undef acct
#undef read
#undef nice
#undef fdetach
#undef vfork
#undef vhangup
#undef brk
#undef ttyname
#undef ttyname_r
#undef isatty
#undef truncate
#undef chdir
#undef gettxt
#undef ftruncate
#undef sysconf
#undef chmod
#undef setpgrp
#undef fchdir
#undef alarm
#undef symlink
#undef tcgetpgrp
#undef access
#undef lockf
#undef getgid
#undef getegid
#undef execl
#undef dup2
#undef dup
#undef pipe
#undef link
#undef execle
#undef fattach
#undef lseek
#undef rename
#undef fork
#undef fork1
#undef close
#undef sbrk
#undef sleep
#undef getpid
#undef _exit
#undef tcsetpgrp
#undef getcwd
#undef execv
#undef ptrace
#undef ioctl
#undef setgid
#undef setegid
#undef execve
#undef getsid
#undef getpgid
#undef execlp
#undef rmdir
#undef pause
#undef getuid
#undef getgroups
#undef readlink
#undef exit
#undef geteuid
#undef chown
#undef ctermid
#undef sync
#undef fchown
#undef stime
#undef fsync
#undef getppid
#undef mincore

extern "C" {
	void _exit(int);
	int access(const char *, int);
	unsigned alarm(unsigned);
	int chdir(const char *);
	int close(int);
	char *ctermid(char *);
	char *cuserid(char *);
	int dup(int);
	int dup2(int, int);
	int execl(const char *, const char *, ...);
	int execle(const char *, const char *, ...);
	int execlp(const char *, const char *, ...);
	long fpathconf(int, int);
	char *getcwd(char *, size_t);
	int isatty(int);
	int link(const char *, const char *);
	off_t lseek(int, off_t, int);
	long pathconf(const char *, int);
	int pipe(int *);
	int rmdir(const char *);
	int setgid(gid_t);
	int setegid(gid_t);
	int setpgid(pid_t, pid_t);
	int setuid(uid_t);
	int seteuid(uid_t);
	long sysconf(int);
	char *ttyname(int);
	char *ttyname_r(int, char *, int);
	int unlink(const char *);
	void exit(int);
	int chown(const char *, uid_t, gid_t);
	int execv(const char *, const char* []);
	int execve(const char *, const char* [], const char* []);
	int execvp(const char *, const char* []);
	pid_t fork(void);
	pid_t fork1(void);
	gid_t getegid(void);
	uid_t geteuid(void);
	gid_t getgid(void);
	int getgroups(int, gid_t*);
	char *getlogin(void);
	char *getlogin_r(char *, int);
	pid_t getpgrp(void);
	pid_t getpid(void);
	pid_t getppid(void);
	uid_t getuid(void);
	int pause(void);
	ssize_t read(int, void *, unsigned);
	int rename(const char *, const char*);
	pid_t setsid(void);
	unsigned sleep(unsigned);
	ssize_t write(int, const void *, unsigned);
        int acct(const char *);
        int brk(void *);
        int chroot(const char *);
	int fchroot(int);
        int fattach(int, const char *);
        int fchdir(int);
        int fchown(int,uid_t, gid_t);
        int fdetach(const char *);
        int fsync(int);
        int ftruncate(int, off_t);
        pid_t getpgid(pid_t);
        char *gettxt(const char *, const char *);
        pid_t getsid(pid_t);
        int ioctl(int, int, ...);
        int lchown(const char *, uid_t, gid_t);
        int lockf(int, int, long);
        int mincore(caddr_t, size_t, char *);
        int nice(int);
        void profil(unsigned short *, unsigned int, unsigned int, unsigned int);
        int ptrace(int, pid_t, int, int);
        int readlink(const char *, void *, int);
        void *sbrk(int);
        int setgroups(int, const gid_t *);
        pid_t setpgrp(void);
        int stime(const time_t *);
        int symlink(const char *, const char *);
        void sync(void);
	pid_t tcgetpgrp(int);
	int tcsetpgrp(int, pid_t);
        int truncate(const char *, off_t);
	pid_t vfork(void);
	void vhangup(void);
}

static void vfork_dummy() {
	/*
	 * The following fucntion is called to keep cfront
	 * from deleting the defintion.  This keeps the
	 * C compiler happy for the following #pragma
	 */
	pid_t dumval = vfork();
}
	
/*
 * This atrocity is necessary on sparc because registers modified
 * by the child get propagated back to the parent via the window
 * save/restore mechanism.
 */
#if !defined(_POSIX_SOURCE)
#ifdef sparc
#pragma unknown_control_flow(vfork)
#endif
#endif /* !defined(_POSIX_SOURCE) */

#endif
