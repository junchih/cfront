#!/bin/sh
#ident	"@(#)cls4:scratch/hp.sed	1.3"
###############################################################################
#
# C++ source for the C++ Language System, Release 3.0.  This product
# is a new release of the original cfront developed in the computer
# science research center of AT&T Bell Laboratories.
#
# Copyright (c) 1993  UNIX System Laboratories, Inc.
# Copyright (c) 1991, 1992 AT&T and UNIX System Laboratories, Inc.
# Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.
#
# THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
#	
# Laboratories, Inc.  The copyright notice above does not evidence
# any actual or intended publication of such source code.
#
###############################################################################
echo "Fixing _iobuf structures:"
FILES=`echo */*..c`
if test "${FILES}" = "*/*..c"
then
	exit
fi
chmod 644 */*..c
for f in */*..c
do
	echo $f
        sed -e '/char _flag__4FILE/s//short _flag__4FILE/g' \
	$f > temp$$
	mv temp$$ $f
done
