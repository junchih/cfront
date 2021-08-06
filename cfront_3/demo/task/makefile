#ident	"@(#)cls4:demo/task/makefile	1.1"
###############################################################################
#
# C++ source for the C++ Language System, Release 3.0.  This product
# is a new release of the original cfront developed in the computer
# science research center of AT&T Bell Laboratories.
#
# Copyright (c) 1991 AT&T and UNIX System Laboratories, Inc.
# Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.
#
# THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
#	
# Laboratories, Inc.  The copyright notice above does not evidence
# any actual or intended publication of such source code.
#
###############################################################################
CC=CC
CCFLAGS=-O
L=../..
LOPT=-L$(L)
#LOPT="-L$(L)"

ALL = triv.E regtest.E shared.E alph.E sigtest.E
NAMES = triv regtest shared alph sigtest

compile: $(ALL)

$(ALL): $(L)/libtask.a

demotask: run

run: $(ALL)
	chmod +x ./runtests
	BSD=$(BSD) ./runtests $(NAMES)

triv.E: ./triv.C
	$(CC) $(CCFLAGS) -o triv.E  ./triv.C $(LOPT) -ltask

regtest.E: ./regtest.C
	$(CC) $(CCFLAGS) -o regtest.E  ./regtest.C $(LOPT) -ltask

shared.E: ./shared.C
	$(CC) $(CCFLAGS) -o shared.E  ./shared.C $(LOPT) -ltask

alph.E: ./alph.C
	$(CC) $(CCFLAGS) -o alph.E  ./alph.C $(LOPT) -ltask

sigtest.E: ./sigtest.C
	$(CC) $(CCFLAGS) -o sigtest.E  ./sigtest.C $(LOPT) -ltask

clean:
	rm -f ./$(ALL)
	rm -f ./*.o
