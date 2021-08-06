/*
 * On some machines, 'union semun' is defined in /usr/include/sys/sem.h.
 * For those systems which don't define 'semun', a definition is provided
 * in our C++ version of sys/sem.h.  This file accounts for the case where
 * you use the system headers on a machine that does not define 'semun'.
 * To get the definition provided below, add -D__ATT_SEMUN to CCFLAGS.
 */

#ifndef __ATT_SEM_H
#define __ATT_SEM_H

#ifdef __ATT_SEMUN
union semun {
	int val;
	struct semid_ds *buf;
	ushort *array;
};
#endif

#endif
