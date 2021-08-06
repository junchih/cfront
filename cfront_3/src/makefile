#ident	"@(#)cls4:src/makefile	1.7"
###############################################################################
#
# C++ source for the C++ Language System, Release 3.0.  This product
# is a new release of the original cfront developed in the computer
# science research center of AT&T Bell Laboratories.
#
# Copyright (c) 1993  UNIX System Laboratories, Inc.
# Copyright (c) 1991,1992   AT&T and UNIX System Laboratories, Inc.
# Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.
#
# THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
#	
# Laboratories, Inc.  The copyright notice above does not evidence
# any actual or intended publication of such source code.
#
###############################################################################
CC	=	CC
YACC	=	yacc

#The ANSI_OUT option has been replaced by the +a1 and +a0 compilation options

#for systems which only recognize identifiers of up to 31 characters
#setting DENSE to -DDENSE causes cfront to generate internal names
#of 31 characters or less 
DENSE=

# The use of RETBUG is nolonger needed with version 2.0 and has been removed.
# RETBUG was used in 1.* Translator versions to circumvent a C compiler bug.

# Uncomment the next line and add -DLICENSE_MAN to the CCFLAGS
# if you want to build a version of cfront that uses a license manager
#
# The LICENSE_LIBS line will change depending upon where your license
# library is located.

#LICENSE_LIBS=Location_of_your_library/libsdelic.a

LICENSE_LIBS=
#CCFLAGS=-O -DLICENSE_MAN
CCFLAGS=-O

# top level makefile modifies the following
MPMACRO	= PATCH
MPFILE	= patch

OFILES	=	alloc.o Bits.o block.o dcl.o dcl2.o dcl3.o dcl4.o \
		del.o discrim.o error.o expand.o \
		expr.o expr2.o expr3.o find.o hash.o lalex.o lex.o main.o \
		norm.o norm2.o print.o print2.o repr.o simpl.o \
		simpl2.o size.o table.o template.o tree_copy.o \
		tree_walk.o typ.o typ2.o y.tab.o 

cfront:	$(OFILES)
	$(CC)	-o cfront $(CCFLAGS) $(OFILES) $(LICENSE_LIBS)

$(OFILES):	cfront.h token.h typedef.h

y.tab.c:	gram.y Block.h cfront.h size.h template.h token.h tqueue.h typedef.h
	$(YACC) gram.y

alloc.o:	alloc.c template.h Block.h cfront.h size.h token.h typedef.h
	$(CC) $(CCFLAGS) -c alloc.c 

Bits.o:	Bits.c Bits.h Block.h
	$(CC) $(CCFLAGS) -c Bits.c 

block.o:	block.c Block.h cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c block.c 

dcl.o:	dcl.c size.h cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c dcl.c 

dcl2.o:	dcl2.c size.h Bits.h Block.h cfront.h overload.h token.h typedef.h
	$(CC) $(CCFLAGS) -c dcl2.c 

dcl3.o:	dcl3.c size.h template.h Block.h cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c dcl3.c 

dcl4.o:	dcl4.c size.h template.h Block.h cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c dcl4.c 

del.o:	del.c cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c del.c 

discrim.o:	discrim.c cfront.h node_classes.h token.h typedef.h
	$(CC) $(CCFLAGS) -c discrim.c

error.o:	error.c size.h template.h Block.h cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c error.c 

expand.o:	expand.c cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c expand.c 

expr.o:	expr.c size.h cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c expr.c 

expr2.o:	expr2.c size.h overload.h template.h Bits.h Block.h cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c expr2.c 

expr3.o:	expr3.c size.h Block.h template.h overload.h Bits.h cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c expr3.c 

find.o:	find.c template.h Block.h cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c find.c 

hash.o: hash.c hash.h
	$(CC) $(CCFLAGS) -c hash.c 

lalex.o:lalex.c yystype.h template.h Block.h cfront.h token.h typedef.h tqueue.h
	$(CC) $(CCFLAGS) -c lalex.c

lex.o:	lex.c size.h Block.h tqueue.h yystype.h template.h cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c lex.c 

# main depends on this makefile to force recompilation
# when going from patch to munch
main.o:	main.c makefile template.h Block.h cfront.h size.h token.h typedef.h
	$(CC) -D$(MPMACRO) $(DENSE) $(CCFLAGS) -c main.c 

norm.o:	norm.c size.h template.h Block.h cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c norm.c 

norm2.o:	norm2.c size.h cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c norm2.c 

print.o:	print.c cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c print.c 

print2.o:	print2.c template.h Block.h cfront.h token.h typedef.h
	$(CC) $(DENSE) $(CCFLAGS) -c print2.c 

repr.o:	repr.c cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c repr.c 

simpl.o:	simpl.c size.h cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c simpl.c 

simpl2.o:	simpl2.c size.h cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c simpl2.c 

size.o:	size.c size.h cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c size.c 

table.o:	table.c cfront.h size.h token.h typedef.h
	$(CC) $(CCFLAGS) -c table.c 

template.o: template.c template.h Block.h cfront.h hash.h node_classes.h token.h typedef.h tree_copy.h tree_walk.h
	$(CC) $(CCFLAGS) -c template.c 

tree_copy.o: tree_copy.c cfront.h hash.h node_classes.h token.h typedef.h tree_copy.h tree_walk.h
	$(CC) $(CCFLAGS) -c tree_copy.c 

tree_walk.o: tree_walk.c node_classes.h cfront.h hash.h token.h typedef.h tree_walk.h
	$(CC) $(CCFLAGS) -c tree_walk.c 

typ.o:	typ.c size.h cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c typ.c 

typ2.o:	typ2.c size.h template.h Block.h cfront.h token.h typedef.h
	$(CC) $(CCFLAGS) -c typ2.c 

y.tab.o:	y.tab.c size.h template.h tqueue.h Block.h cfront.h token.h typedef.h
	$(CC) -DGRAM $(CCFLAGS) -c y.tab.c 

clean:
	rm -f *.o y.tab.c

clobber: clean
	rm -f cfront

cpio:	
	find alloc.c Bits.c block.c dcl.c dcl2.c dcl3.c dcl4.c del.c discrim.c \
		error.c expand.c expr.c expr2.c expr3.c find.c hash.c \
		lalex.c lex.c main.c norm.c norm2.c print.c print2.c \
		repr.c simpl.c simpl2.c size.c table.c \
		template.c tree_copy.c tree_walk.c typ.c typ2.c \
		overload.h gram.y \
		Bits.h Block.h \
		cfront.h token.h size.h tqueue.h typedef.h yystype.h \
		hash.h node_classes.h \
		template.h tree_copy.h tree_walk.h \
		makefile -print | cpio -oc > cfront.cpio

