#ident	"@(#)cls4:demo/stream/makefile	1.1"
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

ALL = lengthdemo.E 
NAMES = lengthdemo

compile: $(ALL)

$(ALL): 

demostream: run

run: $(ALL)
	chmod +x ./runtests
	./runtests $(NAMES)

lengthdemo.E: ./lengthdemo.h ./lengthdemo.C
	$(CC) $(CCFLAGS) -o lengthdemo.E  ./lengthdemo.C 

clean:
	rm -f ./*.E
	rm -f ./*.o
