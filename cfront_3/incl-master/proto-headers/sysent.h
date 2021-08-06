/*ident	"@(#)cls4:incl-master/proto-headers/sysent.h	1.1" */
#usedby all

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
#ifndef __SYSENT_H
#define __SYSENT_H

#ifndef __TYPES_H
#include <sys/types.h>
#endif

#os bsd2 bsd3 sunos3 sunos4 sunos4.1
#ifndef __SYS_TIME_H
#include <sys/time.h>
#endif
#endos

#ifndef __WAIT_H
#include <sys/wait.h>
#endif

#os sunos3 sunos4 sunos4.1
#ifndef __PTRACE_H
#include <sys/ptrace.h>
#endif
#endos

#os svr4 solaris
#ifndef _SYS_PROCSET_H
#include <sys/procset.h>
#endif
#endos

#os svr4 sgi-svr4 solaris
#ifndef __UNISTD_H
#include <unistd.h>
#endif
#endos

extern "C" {
	void _exit(int);
	int access(const char*, int);
	int acct(const char*);
	int chdir(const char*);
	int chroot(const char*);
	int close(int);
	int dup(int);
	void exit(int);
	int ioctl(int, int ...);
	int link(const char*, const char*);
	int nice(int);
	int pause();
	int pipe(int*);
	void sync();
	int unlink(const char*);
	int system(const char*);
	int execl(const char*, const char* ...);
	int execle(const char*, const char* ...);
	int execlp(const char*, const char* ...);
	int execv(const char*, const char*[]);
	int execve(const char*, const char*[], const char*[]);
	int execvp(const char*, const char*[]);

#os svr2 svr3 sgi bsd2 bsd3 hpux2.0 uts sunos3 sunos4 alliant pyramid
	int chmod(const char*, int);
#endos
#os sunos4.1 svr4 sgi-svr4 solaris
	int chmod(const char*, mode_t);
#endos
#os svr4 solaris
#ifndef priocntl
	long priocntl(idtype_t, id_t, int, ...);
#endif
#ifndef priocntlset
	long priocntlset(procset_t *, int, ...);
#endif
#endos
#os svr4 sgi-svr4 solaris
	int adjtime(struct timeval *, struct timeval *);
	int memcntl(caddr_t, size_t, int, caddr_t, int, int);
	int mprotect(caddr_t, size_t, int);
	int swapctl(int, void*);
	int read(int, void*, unsigned);
#endos
#os hpux hpux8.0 svr4 sgi-svr4 solaris
	long ulimit(int, ...);
	mode_t umask(mode_t);
	int fchmod(int, mode_t);
	int creat(const char*, mode_t);
	int mkdir(const char*, mode_t);
	off_t lseek(int, off_t, int);
	int write(int, const void*, unsigned);
#endos
#os hpux 
	int mknod(const char*, mode_t, dev_t);
	int chmod(const char*, mode_t);
#endos
#os hpux8.0
	int mknod(const char*, mode_t, int);
#endos
#os solaris sgi-svr4
        int mknod(const char *, mode_t, dev_t);
#endos
#os svr4
        int _xmknod(const int, const char *, mode_t, dev_t);
#endos
#os svr2 svr3 sgi bsd2 bsd3 hpux2.0 uts sunos3 sunos4 sunos4.1 alliant pyramid
	int chown(const char*, int, int);
	int creat(const char*, int);
	int fork();
	int getpid();
	int getppid();
	int kill(int, int);
	int open(const char*, int, ...);
	long ulimit(int, long);
	int umask(int);
#endos
#os hpux hpux8.0
	int read(int, void*, int);
	int chown(const char*, uid_t, gid_t);
	int fchown(int, uid_t, gid_t);
	pid_t fork();
	pid_t getpid();
	pid_t getppid();
	pid_t getpgrp();
	gid_t getegid();
	uid_t geteuid();
	gid_t getgid();
	uid_t getuid();
	pid_t setpgrp();
	pid_t setsid();
	int getgroups(int, gid_t *);
	int setprivgrp(gid_t, int *);
	int kill(pid_t, int);
	int setuid(uid_t);
	int setgid(gid_t);
	int setgroups(int, gid_t *);
	int fsync(int);
	int getdomainname(char*, int);
	int gethostname(char*, int);
	int readlink(const char*, char*, int);
	int setdomainname(const char*, int);
	int sethostname(const char*, int);
	int shutdown(int, int);
	int swapon(const char*);
	int symlink(const char*, const char*);
	int vfork();
#endos
#os hpux
	size_t sigspace(size_t);
	void profil(const char*, int, int, int);
	int open(const char*, int, ...);
	pid_t getpgrp2(pid_t);
#endos
#os hpux8.0
	int access(const char*, int);
	size_t sigspace(size_t);
	void profil(const void*, size_t, size_t, int);
	int open(const char*, int, ...);
#endos
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	int lockf(int, int, long);
#endos
#os uts
	int rfstart(int);
	int rfstop();
	int unadv(const char*);
	int mkdir(const char*, int);
#endos
#os svr3 sgi
	int rmount(const char *,const char *, const char *, int);
#endos
#os svr2 svr3 sgi uts
	unsigned alarm(unsigned);
	int mount(const char*, const char*, int);
	void profil(const char*, int, int, int);
	int ptrace(int, int, int, int);
	int read(int, void*, unsigned);
	int write(int, const void*, unsigned);
#endos
#os svr2 svr3 sgi
	int openpl();
	int closepl();
	void sys3b(int, int ...);
	unsigned sleep(unsigned);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant svr2 svr3 sgi uts
	int mknod(const char*, int, int);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant svr3 sgi hpux2.0 hpux hpux8.0
	int dup2(int, int);
#endos
#os bsd3 sunos3 sunos4 sunos4.1 alliant svr3 sgi hpux2.0
	int mkdir(const char*, int);
#endos
#os bsd3 sunos3 sunos4 sunos4.1 alliant svr3 sgi hpux2.0 hpux hpux8.0
	int rmdir(const char*);
#endos
#os bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0
	int rename(const char*, const char*);
#endos
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0
	int async_daemon();
#endos
#os bsd2 bsd3
	int sethostid(long);
#endos
#os sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0
	int getdirentries(int, char*, int, long*);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0
	int fchmod(int, int);
	int fchown(int, int, int);
	int fsync(int);
	int getdomainname(char*, int);
	int gethostname(char*, int);
	int getgroups(int, int*);
	void profil(const char*, int, int, int);
	int readlink(const char*, char*, int);
	int setdomainname(const char*, int);
	int setgroups(int, const int*);
	int sethostname(const char*, int);
	int shutdown(int, int);
	int swapon(const char*);
	int symlink(const char*, const char*);
	int vfork();
	int write(int, const char*, int);
	int read(int, char*, int);
#endos
#os hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	int brk(char*);
	int plock(int);
	int stime(const long*);
	int umount(const char*);
#endos
#os hpux2.0 svr2 svr3 sgi uts
	int getpgrp();
	unsigned short getegid();
	unsigned short geteuid();
	unsigned short getgid();
	unsigned short getuid();
	long lseek(int, long, int);
	int setpgrp();
#endos
#os hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	char *sbrk(int);
#endos
#os hpux2.0
	int getpgrp2(int);
	long sigspace(long);
#endos
#os hpux2.0 hpux hpux8.0
	unsigned long sleep(unsigned long);
	unsigned alarm(unsigned long);
	int ftruncate(int, unsigned long);
	int truncate(const char*, unsigned long);
	void lsync();
	int mount(const char*, const char*, int, int);
	int prealloc(int, unsigned);
	int ptrace(int, int, int, int, int);
	int rtprio(int, int);
	int setpgrp2(int, int);
	int setresgid(int, int, int);
	int setresuid(int, int, int);
	long sigblock(long);
	void sys3b(int ...);
#endos
#os bsd2 bsd3 sunos3 alliant
	caddr_t brk(caddr_t);
#endos
#os bsd2 sunos3 alliant
	long lseek(int, long, int);
	int ftruncate(int, unsigned long);
	int truncate(const char*, unsigned long);
#endos
#os bsd3 sunos4 sunos4.1
	off_t lseek(int, off_t, int);
	int ftruncate(int, off_t);
	int truncate(const char*, off_t);
#endos
#os bsd3 sunos3 sunos4 sunos4.1 alliant
	int getdtablesize();
#endos
#os bsd3 sunos4 sunos4.1 alliant
	int flock(int, int);
	long gethostid();
	int getpagesize();
	int killpg(int, int);
	int syscall(int ...);
	int vadvise(int);
#endos
#os sunos4 sunos4.1
	int brk(caddr_t);
	int fchdir(int);
	int fchroot(int);
#endos
#os bsd2 sunos3 alliant svr2 svr3 sgi hpux2.0 uts
	int setuid(int);
	int setgid(int);
#endos
#os sunos4 sunos4.1
	int setuid(uid_t);
	int setgid(gid_t);
#endos
#os bsd2 sunos3 sunos4 sunos4.1 alliant
	int getegid();
	int geteuid();
	int getgid();
	int getuid();
#endos
#os bsd3
	gid_t getegid();
	uid_t geteuid();
	gid_t getgid();
	uid_t getuid();
	int setuid(uid_t);
	int setgid(gid_t);
#endos
#os bsd2 bsd3
	int mount(const char*, const char*, int);
	int umount(const char*);
#endos
#os sunos3 sunos4 sunos4.1 alliant
	int mount(const char*, const char*, int, caddr_t);
	int unmount(const char*);
	int nfssvc(int);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant
	int sleep(unsigned);
	unsigned alarm(unsigned);
	int getpgrp(int);
	caddr_t sbrk(int);
	int setpgrp(int, int);
	int setreuid(int, int);
	int setregid(int, int);
	void vhangup();
#endos
#os bsd2 bsd3 sunos3 sunos4 alliant
	int setegid(int);
	int seteuid(int);
	int setrgid(int);
	int setruid(int);
#endos
#os sunos4.1
	int setegid(gid_t);
	int seteuid(uid_t);
	int setrgid(gid_t);
	int setruid(uid_t);
#endos
#os svr4
#ifndef _SVR4_MKNOD_FUNC
#define _SVR4_MKNOD_FUNC
#ifndef _MKNOD_VER
#define _MKNOD_VER 2            /* current version of mknod */
#endif
static inline int
mknod( const char *path, mode_t mode, dev_t dev )
{
        return _xmknod(_MKNOD_VER, path, mode, dev);
}
#endif
#endos
}

#endif
