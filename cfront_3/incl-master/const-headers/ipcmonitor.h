/*ident	"@(#)ipc:incl/ipcmonitor.h	3.1" */
/******************************************************************************
*
* C++ Standard Components, Release 3.0.
*
* Copyright (c) 1991, 1992 AT&T and Unix System Laboratories, Inc.
* Copyright (c) 1988, 1989, 1990 AT&T.  All Rights Reserved.
*
* THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T and Unix System
* Laboratories, Inc.  The copyright notice above does not evidence
* any actual or intended publication of such source code.
*
******************************************************************************/

#ifndef IPCMONITORH
#define IPCMONITORH

#ifndef SYS_TYPES_H
#define SYS_TYPES_H
#include <sys/types.h>
#endif

#include <sys/ipc.h>
#include <sys/sem.h>
#include <att_sem.h>
#include <stream.h>
#include <errno.h>

const int	MONITORPERM	= 0666;		// permission


class Monitor {
	key_t	semkey;		// semaphore key
	int	semid;		// semaphore id
	int	semcnt;		// semaphore count

	int	pvop(int op);

public:
	Monitor(key_t key = IPC_PRIVATE, int cnt = 1)
		: semkey(key), semid(-1), semcnt(cnt) {}
	~Monitor() {}

	int Open();		// create or open semaphore
	int Close();		// remove semaphore
	int GetSemKey() {	// get semaphore key
		return semkey;
	    }
	int GetSemId() {	// get semaphore id
		return semid;
	    }
	int P();		// semaphore P oeration
	int V();		// semaphore V oeration
};


inline int
Monitor::pvop(int op)
{
	struct sembuf	sb;
	sb.sem_num = 0;
	sb.sem_op = op;
	sb.sem_flg = SEM_UNDO;

	return (semop(semid, &sb, 1) == -1) ? -1 : 0;
}


inline int
Monitor::Close()
{
	semun arg;
	int ret;

	arg.val = 0;
	if( (ret = semctl(semid,1,IPC_RMID,arg)) < 0 ) {
	    cerr << "semctl IPC_RMID error; errno =" << errno << endl;
	}
	semid = -1;
	return ret;
}


inline int
Monitor::Open()
{
	semun arg;
	if( semid < 0 ) {
	    if( (semid = ::semget(semkey,1,
			     (IPC_CREAT|IPC_EXCL|MONITORPERM))) < 0 ) {
		if( (semid = ::semget(semkey,1,!IPC_CREAT)) < 0 ) {
			cerr << "sema get error; semkey=" << semkey << 
				",errno=" << errno << endl;
		}
	    }
	    else {
		arg.val = semcnt;
		if( ::semctl(semid,0,SETVAL,arg) < 0 ) {
			cerr << "semctl SETVAL error; semid=" << semid
			     << ",errno=" << errno << endl;
			(void)Close();
		}
	    }
	}
	return semid;
}

inline int
Monitor::P()
{
	return pvop(-1);
}
	
inline int
Monitor::V()
{
	return pvop(1);
}

#endif
