#ident	"@(#)cls4:lib/mk/makefile	1.3"
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
O_GENERIC	=	generic.o
O_NEW		=	_new.o _delete.o _handler.o _vec.o placenew.o _arr_map.o
O_STATIC	=	_ctor.o _dtor.o _main.o exit.o dtors.o pure.o
O_STREAM	=	in.o out.o stream.o fstream.o manip.o cstreams.o \
flt.o strstream.o rawin.o intin.o stdiobuf.o streambuf.o \
filebuf.o  oldformat.o sbuf.dbp.o swstdio.o ios_compat.o
OFILES	=	$(O_GENERIC) $(O_NEW) $(O_STATIC) $(O_STREAM) 
CC	=	CC
CCFLAGS	=-O

# have everything depend on this makefile to force recompilation
# when going from patch to munch
DEPEND	= makefile

MPDIR	= Patch
MPFILE	= patch

libC.a:	$(OFILES)
	ar r libC.a `lorder $? | tsort 2> /dev/null`
	if test "$(BSD)" ; then ranlib libC.a; fi

generic.o:	../generic/generic.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../generic/generic.c

_delete.o:	../new/_delete.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../new/_delete.c

_handler.o:	../new/_handler.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../new/_handler.c

_new.o:	../new/_new.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../new/_new.c

_vec.o:	../new/_vec.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../new/_vec.c

placenew.o: ../new/placenew.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../new/placenew.c

_arr_map.o: ../new/_arr_map.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../new/_arr_map.c

_ctor.o:	../static/_ctor.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../static/_ctor.c

_dtor.o:	../static/_dtor.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../static/_dtor.c

_main.o:	../../$(MPDIR)/_main.c ../../$(MPFILE) $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../../$(MPDIR)/_main.c

dtors.o:	../../$(MPDIR)/dtors.c ../../$(MPFILE) $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../../$(MPDIR)/dtors.c

exit.o:	../static/exit.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../static/exit.c

pure.o: ../static/pure.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../static/pure.c

in.o:	../stream/in.c  $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/in.c

out.o:	../stream/out.c  ../stream/streamdefs.h $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/out.c

stream.o:	../stream/stream.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/stream.c

fstream.o:	../stream/fstream.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/fstream.c

manip.o:	../stream/manip.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/manip.c

cstreams.o:	../stream/cstreams.c ../stream/streamdefs.h $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/cstreams.c

flt.o:	../stream/flt.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/flt.c

strstream.o:	../stream/strstream.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/strstream.c

rawin.o:	../stream/rawin.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/rawin.c

intin.o:	../stream/intin.c  $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/intin.c

stdiobuf.o:	../stream/stdiobuf.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/stdiobuf.c

streambuf.o:	../stream/streambuf.c ../stream/streamdefs.h $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/streambuf.c

filebuf.o:	../stream/filebuf.c ../stream/streamdefs.h $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/filebuf.c

oldformat.o:	../stream/oldformat.c ../stream/streamdefs.h $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/oldformat.c

sbuf.dbp.o:	../stream/sbuf.dbp.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/sbuf.dbp.c

swstdio.o:	../stream/swstdio.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/swstdio.c

ios_compat.o:	../stream/ios_compat.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/ios_compat.c
