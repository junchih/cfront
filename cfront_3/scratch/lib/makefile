#ident	"@(#)cls4:scratch/lib/makefile	1.3"
###############################################################################
#
# C++ source for the C++ Language System, Release 3.0.  This product
# is a new release of the original cfront developed in the computer
# science research center of AT&T Bell Laboratories.
#
# Copyright (c) 1993  UNIX System Laboratories, Inc.
# Copyright (c) 1991, 1992  AT&T and UNIX System Laboratories, Inc.
# Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.
#
# THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
#	
# Laboratories, Inc.  The copyright notice above does not evidence
# any actual or intended publication of such source code.
#
###############################################################################
LIBFILES=_ctor..c _delete..c _dtor..c _handler..c _main..c _new..c \
_vec..c placenew..c _arr_map..c dtors..c pure..c exit..c munch..c

SZAL=

CC=

FILLDEF=
FILLUNDEF=

all: $(LIBFILES) 

munch..c: ../../Munch/munch.c
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../Munch/munch.c

_ctor..c: ../../lib/static/_ctor.c
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../lib/static/_ctor.c

_delete..c: ../../lib/new/_delete.c
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c  ../../lib/new/_delete.c

_dtor..c:  ../../lib/static/_dtor.c
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../lib/static/_dtor.c

_handler..c:  ../../lib/new/_handler.c
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../lib/new/_handler.c

_main..c: ../../Munch/_main.c
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../Munch/_main.c

_new..c: ../../lib/new/_new.c
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../lib/new/_new.c

_vec..c: ../../lib/new/_vec.c
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c  ../../lib/new/_vec.c

placenew..c: ../../lib/new/placenew.c
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c  ../../lib/new/placenew.c

_arr_map..c: ../../lib/new/_arr_map.c
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c  ../../lib/new/_arr_map.c

pure..c: ../../lib/static/pure.c
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../lib/static/pure.c

dtors..c: ../../Munch/dtors.c
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../Munch/dtors.c

exit..c: ../../lib/static/exit.c
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../lib/static/exit.c
