#ident	"@(#)cls4:incl-master/makefile	1.1"
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
###############################################################################
#
# This makefile can produce header files for the following OS's:
# 4.2BSD, 4.3BSD, SUN, ALLIANT, HPUX, SVR2, SVR3, SVR4, UTS
#
# Please don't try cross-building header files (i.e., building
# header files for one operating system on a machine of another
# operating system).
#
# Please also note that while we produce headers for certain OS's
# such as ALLIANT and UTS, the entire product has not been completely
# tested on these systems and you may therefore need to make adjustments
# in other areas of the product to use the translator on such systems.

# Choose one of {sun, sunos3, sunos4, sunos4.1, bsd2, bsd3, hpux, hpux8.0, alliant,
# svr2, svr3, uts, sgi, pyramid, solaris}.  If you choose sun, the scripts will apply a
# heuristic to tell whether you're running os3, os4, or os4.1.
#
OS=svr4

# This is the name of the subdirectory where the C++ headers wind up.
# If you are building the headers from within cfront's top level makefile,
# the headers will eventually be moved up to the top level incl directory.
#
TARGET=incl

# Be verbose?
#
VERBOSE=1

# Set this to 1 if your machine has symbolic links, *and* you
# want to use symbolic links in your C++ header files.  However,
# always leave it set at 0 when doing a port of the headers to
# another operating system.  For help on doing a port, consult
# the C++ Translator document.
#
SYMBOLICLINK=0

# If you set SYMBOLICLINK=1, then you must set STDINCL to the
# directory containing the standard C header files on your
# machine.  (If your standard C header files are distributed
# all over the place (e.g., uts) , then you can't use symbolic
# links.)
#
STDINCL=/usr/include

# If you just want to generate certain headers, set the following
# variable to the list of their names.  For example,
# HEADERS=foo.h bar.h
#
HEADERS=

# To implementers: If you want to change the directory from
# which the proto-header files are gotten, set and export the
# shell variable PROTOHEADERS.

###############################################################################
# You shouldn't have to change anything below this line.
###############################################################################

BINARIES=expand stddef2

build_them: $(OS) $(BINARIES) chmods
	./build $(OS) ${STDINCL} ${SYMBOLICLINK} ${VERBOSE} ${TARGET} "${HEADERS}"

use_sys:
	chmod +x copy_const
	./copy_const $(OS) ${STDINCL} ${VERBOSE} ${TARGET}
chmods:
	chmod +x build nochange stdcat stddef transform solaris.fix sgi4.fix

sun:
sunos3:
sunos4:
sunos4.1:
solaris:
bsd2:
bsd3:
hpux:
hpux8.0:
svr2:
svr3:
uts:
sgi:
sgi-svr4:
pyramid:
svr4:
svr4FT:
3b2mips:

expand:	expand.c
	cc -o expand expand.c

stddef2:stddef2.c
	cc -o stddef2 stddef2.c

always:

clean:
	/bin/rm -fr expand stddef2 ${TARGET}.temp

clobber: clean
	/bin/rm -fr ${TARGET} ${TARGET}.OLD
