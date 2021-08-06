/*ident	"@(#)cls4:incl-master/proto-headers/sys/bitmap.h	1.1" */
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
#ifndef __SYS_BITMAP_H
#define __SYS_BITMAP_H

#hide bt_availbit
#hide bt_gethighbit
#hide bt_range

#expand sys/bitmap.h

extern "C" {
	index_t bt_availbit(ulong *bitmap, size_t nbits);
	void bt_gethighbit(ulong *mapp, int wx, int *bitposp);
	int bt_range(ulong *bitmap, size_t *pos1, size_t *pos2, size_t nbits);
}

#endif
