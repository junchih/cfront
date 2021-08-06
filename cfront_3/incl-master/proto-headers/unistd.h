/*ident	"@(#)cls4:incl-master/proto-headers/unistd.h	1.1" */
#usedby sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts sunos4.1 svr4 sgi-svr4 

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
#ifndef __UNISTD_H
#define __UNISTD_H

#os sunos4 sunos4.1 svr4 sgi-svr4
#ifndef __TYPES_H
#include <sys/types.h>
#endif
#endos

#os sunos3 sunos4 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
#hide utime
#endos

#os sgi-svr4
#hide getenv
#hide getwd
#endos

#os sunos3
#hide lockf
#endos

#os svr4 sgi-svr4
#hide exit
#hide rename
#hide acct
#hide brk
#hide chroot
#hide fattach
#hide fchdir
#hide fchown
#hide fdetach
#hide fsync
#hide ftruncate
#hide getpgid
#hide gettxt
#hide getsid
#hide ioctl
#hide lchown
#hide mincore
#hide nice
#hide profil
#hide ptrace
#hide readlink
#hide sbrk
#hide setgroups
#hide setpgrp
#hide stime
#hide swab
#hide symlink
#hide sync
#hide truncate
#hide vfork
#endos

#os hpux8.0
#hide _exit
#hide access
#hide chdir
#hide chown
#hide close
#hide ctermid
#hide cuserid
#hide dup
#hide dup2
#hide execl
#hide execle
#hide execlp
#hide execv
#hide execve
#hide execvp
#hide fpathconf
#hide getcwd
#hide getlogin
#hide getgroups
#hide isatty
#hide link
#hide lseek
#hide pathconf
#hide pause
#hide pipe
#hide rmdir
#hide setgid
#hide setpgid
#hide setsid
#hide setuid
#hide sleep
#hide sysconf
#hide tcgetpgrp
#hide tcsetpgrp
#hide ttyname
#hide unlink
#hide write
#hide read
#hide alarm
#hide fork
#hide getuid
#hide geteuid
#hide getgid
#hide getegid
#hide getpid
#hide getpgrp
#hide getppid
#hide fnmatch
#hide getopt
#hide confstr
#hide crypt
#hide encrypt
#hide fsync
#hide getpass
#hide nice
#hide swab
#hide brk  
#hide chroot
#hide endusershell
#hide fchown       
#hide ftruncate
#hide getcdf    
#hide getcontext
#hide gethcwd    
#hide gethostname
#hide getpgrp2
#hide getusershell
#hide hidecdf
#hide initgroups
#hide ioctl
#hide is_68010_present
#hide is_68881_present
#hide is_98248A_present
#hide is_98635A_present
#hide lockf
#hide logname
#hide lsync
#hide mkstemp
#hide mktemp
#hide prealloc
#hide readlink
#hide sbrk
#hide setgroups
#hide sethostname
#hide setpgrp2
#hide setresgid
#hide setresuid
#hide setusershell
#hide sgetl
#hide sputl
#hide swapon
#hide symlink
#hide sync
#hide truncate
#hide ttyname
#hide ttyslot
#hide setpgrp
#hide vfork
#endos

#os sunos4 sunos4.1 svr4 sgi-svr4

#hide _exit
#hide access
#hide alarm
#hide chdir
#hide chmod
#hide chown
#hide close
#hide ctermid
#hide cuserid
#hide dup
#hide dup2
#hide execl
#hide execle
#hide execlp
#hide execv
#hide execve
#hide execvp
#hide fork
#hide fpathconf
#hide getcwd
#hide getegid
#hide geteuid
#hide getgid
#hide getgroups
#hide getlogin
#hide getpgrp
#hide getpid
#hide getppid
#hide getuid
#hide isatty
#hide link
#hide lockf
#hide lseek
#hide pathconf
#hide pause
#hide pipe
#hide read
#hide rmdir
#hide setgid
#hide setpgid
#hide setsid
#hide setuid
#hide sleep
#hide sysconf
#hide tcgetpgrp
#hide tcsetpgrp
#hide ttyname
#hide unlink
#hide write
#endos

#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4
#expand unistd.h
#endos

#os hpux8.0
#include <stdlib.h>
#include <sysent.h>
#endos

extern "C" {
#os hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	int utime(const char *, struct utimbuf *);
#endos
#os sunos3 sunos4 sunos4.1
	int lockf(int, int, long);
	int access (const char*, int);
#endos
#os sunos3 sunos4
	int utime(char *, time_t *);
#endos
#os sunos3
	long lseek(int, long, int);
#endos
#os sunos4 sunos4.1
	off_t lseek(int, off_t, int);
#endos
}

extern "C" {
#os sunos4
	int chmod(const char *, int);
#endos
#os sunos4.1
	int chmod(const char *, mode_t);
#endos
#os sgi-svr4
	char* getwd(char *);
	int gethostname(char *, int);
#endos
#os sunos4 sunos4.1 svr4 sgi-svr4
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
	char *getcwd(char *, int);
	int isatty(int);
	int link(const char *, const char *);
	off_t lseek(int, off_t, int);
	long pathconf(const char *, int);
	int pipe(int *);
	int rmdir(const char *);
	int setgid(gid_t);
	int setuid(uid_t);
	long sysconf(int);
	char *ttyname(int);
	int unlink(const char *);
#endos
#os sunos4.1
	int setpgid(pid_t, pid_t);
	int tcsetpgrp(int, pid_t);
	pid_t tcgetpgrp(int);
	pid_t fork();
	pid_t getpid();
	pid_t getppid();
	pid_t setsid();
#endos
#os sunos4
	int fork();
	int getpid();
	int getppid();
#endos
#os sunos4 sunos4.1
	int chown(const char *, int, int);
	int execv(const char *, const char **);
	int execve(const char *, const char **, const char **);
	int execvp(const char *, const char **);
	int getegid();
	int geteuid();
	int getgid();
	int getgroups(int, int*);
	char *getlogin();
	int getpgrp(int);
	int getuid();
	int pause();
	int read(int, char *, int);
        int setgroups(int, const int *);
	int sleep(unsigned);
	int write(int, const char *, int);
#endos
#os svr4 sgi-svr4
	void exit(int);
	int chown(const char *, uid_t, gid_t);
	int execv(const char *, const char *[]);
	int execve(const char *, const char *[], const char *[]);
	int execvp(const char *, const char *[]);
	pid_t fork(void);
	gid_t getegid(void);
	uid_t geteuid(void);
	gid_t getgid(void);
	int getgroups(int, gid_t*);
	char *getlogin(void);
	pid_t getpgrp(void);
	pid_t getpid(void);
	pid_t getppid(void);
	uid_t getuid(void);
	int pause(void);
	int read(int, void *, unsigned);
	int rename(const char *, const char*);
	pid_t setsid(void);
	unsigned sleep(unsigned);
	int write(int, const void *, unsigned);
        int acct(const char *);
        int brk(void *);
        int chroot(const char *);
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
        int truncate(const char *, off_t);
        pid_t vfork(void);
#endos
}

#endif
