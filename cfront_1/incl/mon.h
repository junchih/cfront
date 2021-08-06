/* @(#) mon.h 1.3 2/16/87 11:02:23 */
/*ident	"@(#)cfront:incl/mon.h	1.3"*/

#ifndef MONH
#define MONH

struct hdr {
	char	*lpc;
	char	*hpc;
	int	nfns;
};

struct cnt {
	char	*fnpc;
	long	mcnt;
};

typedef unsigned short WORD;

#define MON_OUT	"mon.out"
#define MPROGS0	(150 * sizeof(WORD))	/* 300 for pdp11, 600 for 32-bits */
#define MSCALE0	4
#define NULL	0

#ifndef PFSEEN
#define PFSEEN
typedef int (*PF) ();
#endif

extern  void monitor (PF, PF, WORD*, int, int);

#endif

