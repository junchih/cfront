/*ident	"@(#)cls4:incl-master/proto-headers/sys/dma.h	1.1" */
#usedby svr4 

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
#ifndef __SYS_DMA_H
#define __SYS_DMA_H

#hide dma_init
#hide dma_intr
#hide dma_prog
#hide dma_swsetup
#hide dma_swstart
#hide dma_stop
#hide dma_enable
#hide dma_disable
#hide dma_get_cb
#hide dma_free_cb
#hide dma_get_buf
#hide dma_free_buf

#expand sys/dma.h

extern "C" {
	void            dma_init(void);
	void            dma_intr(int);
	int             dma_prog(struct dma_cb *, int, unsigned char);
	int             dma_swsetup(struct dma_cb *, int, unsigned char);
	void            dma_swstart(struct dma_cb *, int, unsigned char);
	void            dma_stop(int);
	void            dma_enable(int);
	void            dma_disable(int);
	struct dma_cb  *dma_get_cb(unsigned char);
	void            dma_free_cb(struct dma_cb *);
	struct dma_buf *dma_get_buf(unsigned char);
	void            dma_free_buf(struct dma_buf *);
}

#endif
