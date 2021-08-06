#ident	"@(#)cls4:lib/complex/mk/makefile	1.3"
###############################################################################
#
# C++ source for the C++ Language System, Release 3.0.  This product
# is a new release of the original cfront developed in the computer
# science research center of AT&T Bell Laboratories.
#
# Copyright (c) 1993  UNIX System Laboratories, Inc.
# Copyright (c) 1991, 1992   AT&T and UNIX System Laboratories, Inc.
# Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.
#
# THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
#	
# Laboratories, Inc.  The copyright notice above does not evidence
# any actual or intended publication of such source code.
#
###############################################################################
O_COMPLEX	=	abs.o arg.o cos.o error.o exp.o io.o log.o oper.o \
			polar.o pow.o sin.o sqrt.o
CC	=	CC
CCFLAGS	= -DPRAGMATIC

libcomplex.a:	$(O_COMPLEX)
	ar r libcomplex.a $(O_COMPLEX)
	if test "$(BSD)" ; then ranlib libcomplex.a; fi

libcomplex_b.a:	$(O_COMPLEX)
	ar r libcomplex_b.a $(O_COMPLEX)
	if test "$(BSD)" ; then ranlib libcomplex_b.a; fi

libcomplex_eh.a:	$(O_COMPLEX)
	ar r libcomplex_eh.a $(O_COMPLEX)
	if test "$(BSD)" ; then ranlib libcomplex_eh.a; fi

libcomplex_p.a:	$(O_COMPLEX)
	ar r libcomplex_p.a $(O_COMPLEX)
	if test "$(BSD)" ; then ranlib libcomplex_p.a; fi

abs.o:	../complex/abs.c
	$(CC) $(CCFLAGS) -I../complex -c ../complex/abs.c

arg.o:	../complex/arg.c
	$(CC) $(CCFLAGS) -I../complex -c ../complex/arg.c

cos.o:	../complex/cos.c
	$(CC) $(CCFLAGS) -I../complex -c ../complex/cos.c

error.o:	../complex/error.c
	$(CC) $(CCFLAGS) -I../complex -c ../complex/error.c

exp.o:	../complex/exp.c
	$(CC) $(CCFLAGS) -I../complex -c ../complex/exp.c

io.o:	../complex/io.c
	$(CC) $(CCFLAGS) -I../complex -c ../complex/io.c

log.o:	../complex/log.c
	$(CC) $(CCFLAGS) -I../complex -c ../complex/log.c

oper.o:	../complex/oper.c
	$(CC) $(CCFLAGS) -I../complex -c ../complex/oper.c

polar.o:	../complex/polar.c
	$(CC) $(CCFLAGS) -I../complex -c ../complex/polar.c

pow.o:	../complex/pow.c
	$(CC) $(CCFLAGS) -I../complex -c ../complex/pow.c

sin.o:	../complex/sin.c
	$(CC) $(CCFLAGS) -I../complex -c ../complex/sin.c

sqrt.o:	../complex/sqrt.c
	$(CC) $(CCFLAGS) -I../complex -c ../complex/sqrt.c

clean:
	rm -f $(O_COMPLEX)
