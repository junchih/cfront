#!/bin/sh
#ident	"@(#)cls4:incl-master/const-headers/cpio.sh	1.2"
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
#
# A directory-tree copy command based loosely on cpio -p.  Allows the
# building and installation of cfront on systems which don't have the
# cpio command (if any such systems still exist).
#

link=0
verbose=

case $1 in -*)
	case $1 in *i*|*o*)
		echo "$0: error: can only be used in pass mode"
		exit 1
	;;esac
	case $1 in *l*)
		link=1
	;;esac
	case $1 in *v*)
		verbose=-x
	;;esac
	shift
;;esac

case $# in 1) ;;*)
	echo "usage: $0 [ -lv ] target"
	exit 1
;;esac

sed 's/^\.\///' |
xargs ls -ld |
case $link in 0)
	awk '	BEGIN { TARG = "'$1'"; or = "2>/dev/null ||"; }
		$NF == "." || $NF == ".." { next; }
		/^l/ { print "ln -s", $NF, TARG "/" $(NF-2), or; }
		/^-/ { print "cp "  , $NF, TARG "/" $NF, or; }
		/^d/ { print "mkdir", TARG "/" $NF, or; }
		$1 ~ /^-/ || $1 ~ /^[ld]/ { print "exit 1"; }
		END { print "exit 0"; }'
;;*)
	awk '	BEGIN { TARG = "'$1'"; or = "2>/dev/null ||"; }
		$NF == "." || $NF == ".." { next; }
		/^l/ { print "ln -s", $NF, TARG "/" $(NF-2), or; }
		/^-/ {
			print "ln "  , $NF, TARG "/" $NF, or;
			print "cp "  , $NF, TARG "/" $NF, or;
		}
		/^d/ { print "mkdir", TARG "/" $NF, or; }
		$1 ~ /^-/ || $1 ~ /^[ld]/ { print "exit 1"; }
		END { print "exit 0"; }'
;;esac |
sh $verbose
exit $?
