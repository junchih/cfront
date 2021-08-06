#ident	"@(#)cls4:demo/generic/makefile	1.1"
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
CC = CC
CCFLAGS = -O

ALL = Vector.E Generic.E
NAMES = Vector Generic

compile: $(ALL)

$(ALL):

demogeneric: run

run : $(ALL)
	chmod +x ./runtests
	./runtests $(NAMES)

Vector.E:	Vector.C
	$(CC) $(CCFLAGS) -o Vector.E Vector.C

Generic.E:	Generic.C
	$(CC) $(CCFLAGS) -o Generic.E Generic.C

clean:
	rm -f ./*.E
	rm -f ./*.o
