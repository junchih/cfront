#ident	"@(#)cls4:lib/mk/makefile	1.1"
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

libC_p.a:	$(OFILES)
	ar r libC_p.a `lorder $? | tsort 2> /dev/null`
	if test "$(BSD)" ; then ranlib libC_p.a; fi

generic.o:	../generic/generic.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c -p ../generic/generic.c

_delete.o:	../new/_delete.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c -p ../new/_delete.c

_handler.o:	../new/_handler.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c -p ../new/_handler.c

_new.o:	../new/_new.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c -p ../new/_new.c

_vec.o:	../new/_vec.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c -p ../new/_vec.c

placenew.o: ../new/placenew.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c -p ../new/placenew.c

_arr_map.o: ../new/_arr_map.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c -p ../new/_arr_map.c

_ctor.o:	../static/_ctor.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c -p ../static/_ctor.c

_dtor.o:	../static/_dtor.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c -p ../static/_dtor.c

_main.o:	../../$(MPDIR)/_main.c ../../$(MPFILE) $(DEPEND)
	$(CC) $(CCFLAGS)  -c -p ../../$(MPDIR)/_main.c

dtors.o:	../../$(MPDIR)/dtors.c ../../$(MPFILE) $(DEPEND)
	$(CC) $(CCFLAGS)  -c -p ../../$(MPDIR)/dtors.c

exit.o:	./exit.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c -p ./exit.c

pure.o: ../static/pure.c $(DEPEND)
	$(CC) $(CCFLAGS)  -c -p ../static/pure.c

in.o:	../stream/in.c  $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c -p ../stream/in.c

out.o:	../stream/out.c  ../stream/streamdefs.h $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c -p ../stream/out.c

stream.o:	../stream/stream.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c -p ../stream/stream.c

fstream.o:	../stream/fstream.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c -p ../stream/fstream.c

manip.o:	../stream/manip.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c -p ../stream/manip.c

cstreams.o:	../stream/cstreams.c ../stream/streamdefs.h $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c -p ../stream/cstreams.c

flt.o:	../stream/flt.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c -p ../stream/flt.c

strstream.o:	../stream/strstream.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c -p ../stream/strstream.c

rawin.o:	../stream/rawin.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c -p ../stream/rawin.c

intin.o:	../stream/intin.c  $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c -p ../stream/intin.c

stdiobuf.o:	../stream/stdiobuf.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c -p ../stream/stdiobuf.c

streambuf.o:	../stream/streambuf.c ../stream/streamdefs.h $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c -p ../stream/streambuf.c

filebuf.o:	../stream/filebuf.c ../stream/streamdefs.h $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c -p ../stream/filebuf.c

oldformat.o:	../stream/oldformat.c ../stream/streamdefs.h $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c -p ../stream/oldformat.c

sbuf.dbp.o:	../stream/sbuf.dbp.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c -p ../stream/sbuf.dbp.c

swstdio.o:	../stream/swstdio.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c -p ../stream/swstdio.c

ios_compat.o:	../stream/ios_compat.c $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c -p ../stream/ios_compat.c
