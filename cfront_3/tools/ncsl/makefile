###############################################################################
#                       Copyright (c) 1984 AT&T
#                         All Rights Reserved
#
#       THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T
#
#       The copyright notice above does not evidence any
#       actual or intended publication of such source code.
#
###############################################################################

# Set this to the C compiler on your machine
CC	= cc

###############################################################################
# You shouldn't have to change anything below this line.
###############################################################################

BIN	= /usr/local/bin
MAN	= /usr/man/man1
CFLAGS	= 

all:    ncsl ncsldiff

ncsl:	ncsl.c
	$(CC) $(CFLAGS) ncsl.c -o ncsl

ncsldiff:	ncsldiff.c
	$(CC) $(CFLAGS) ncsldiff.c -o ncsldiff

install:	all
	strip ncsl ncsldiff
	#/bin/cp ncsl.1 ncsldiff.1 $(MAN)
	/bin/cp ncsl ncsldiff $(BIN)

clean:;	@: nothing to clean

clobber:	clean
	/bin/rm -f ncsl ncsldiff
