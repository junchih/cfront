/*ident	"@(#)cls4:incl-master/proto-headers/sys/mkdev.h	1.1" */
#usedby svr4 solaris

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
#ifndef __SYS_MKDEV_H
#define __SYS_MKDEV_H

#expand sys/mkdev.h

#os svr4 sgi-svr4 solaris
extern "C" {
	dev_t makedev(const major_t, const minor_t);
	major_t major(const dev_t);
	minor_t minor(const dev_t);
	dev_t __makedev(const int, const major_t, const minor_t);
	major_t __major(const int, const dev_t);
	minor_t __minor(const int, const dev_t);
}
#define OLDDEV 0        /* old device format */
#define NEWDEV 1        /* new device format */
static inline dev_t
makedev(const major_t maj, const minor_t min)
{
int ver;
#if !defined(_STYPES)
        ver = NEWDEV;
#else
        ver = OLDDEV;
#endif

        return(__makedev(ver, maj, min));
}

static inline major_t
major(const dev_t dev)
{
int ver;
#if !defined(_STYPES)
        ver = NEWDEV;
#else
        ver = OLDDEV;
#endif

        return(__major(ver, dev));
}

static inline minor_t
minor(const dev_t dev)
{          
int ver;
#if !defined(_STYPES)
        ver = NEWDEV; 
#else                 
        ver = OLDDEV;
#endif                
       
        return(__minor(ver, dev));
}
#endos

#endif
