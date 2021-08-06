#ident	"@(#)cls4:scratch/src/makefile	1.3"
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

SRCFILES=alloc..c Bits..c block..c dcl..c dcl2..c dcl3..c dcl4..c \
	del..c discrim..c error..c expand..c \
	expr..c expr2..c expr3..c find..c hash..c lalex..c lex..c  main..c \
	norm..c norm2..c print..c print2..c repr..c simpl..c \
	simpl2..c size..c table..c template..c tree_copy..c \
	tree_walk..c typ..c typ2..c y.tab..c

SZAL=

CC=CC

FILLDEF=
FILLUNDEF=

all: $(SRCFILES)

cfront.h:       ../../src/token.h ../../src/typedef.h

y.tab.c:        ../../src/gram.y
	yacc ../../src/gram.y
	mv y.tab.c ../../src/y.tab.c

alloc..c: ../../src/alloc.c ../../src/cfront.h ../../src/template.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/alloc.c

Bits..c: ../../src/Bits.c ../../src/Bits.h ../../src/Block.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/Bits.c

block..c: ../../src/block.c ../../src/Block.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/block.c

dcl..c: ../../src/dcl.c ../../src/cfront.h ../../src/size.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/dcl.c

dcl2..c: ../../src/dcl2.c ../../src/cfront.h ../../src/size.h ../../src/overload.h ../../src/template.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/dcl2.c

dcl3..c: ../../src/dcl3.c ../../src/cfront.h ../../src/size.h ../../src/template.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c  ../../src/dcl3.c

dcl4..c: ../../src/dcl4.c ../../src/cfront.h ../../src/size.h ../../src/template.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c  ../../src/dcl4.c

del..c:  ../../src/del.c ../../src/cfront.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/del.c

discrim..c:  ../../src/discrim.c ../../src/cfront.h ../../src/node_classes.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/discrim.c

error..c: ../../src/error.c ../../src/cfront.h ../../src/size.h ../../src/template.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/error.c

expand..c: ../../src/expand.c ../../src/cfront.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/expand.c

expr..c: ../../src/expr.c ../../src/cfront.h ../../src/size.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/expr.c

expr2..c: ../../src/expr2.c ../../src/cfront.h ../../src/size.h ../../src/overload.h ../../src/template.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/expr2.c

expr3..c: ../../src/expr3.c ../../src/cfront.h ../../src/size.h ../../src/Block.h ../../src/template.h ../../src/overload.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/expr3.c

find..c: ../../src/find.c ../../src/cfront.h ../../src/template.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/find.c

hash..c: ../../src/hash.c ../../src/cfront.h ../../src/hash.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/hash.c

lalex..c: ../../src/lalex.c ../../src/cfront.h ../../src/yystype.h ../../src/tqueue.h ../../src/template.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/lalex.c

lex..c: ../../src/lex.c ../../src/cfront.h ../../src/size.h ../../src/tqueue.h ../../src/yystype.h ../../src/template.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c  ../../src/lex.c

main..c: ../../src/main.c ../../src/cfront.h ../../src/makefile ../../src/template.h
	$(CC) $(FILLDEF) $(FILLUNDEF)  $(SZAL) -Fc -..c ../../src/main.c

norm..c: ../../src/norm.c ../../src/cfront.h ../../src/size.h ../../src/template.h
	$(CC) $(FILLDEF) $(FILLUNDEF)  $(SZAL) -Fc -..c ../../src/norm.c

norm2..c: ../../src/norm2.c ../../src/cfront.h ../../src/size.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/norm2.c

print..c: ../../src/print.c ../../src/cfront.h
	$(CC)  $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/print.c

print2..c: ../../src/print2.c ../../src/cfront.h ../../src/template.h
	$(CC)  $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/print2.c

repr..c:  ../../src/repr.c ../../src/cfront.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/repr.c

simpl..c: ../../src/simpl.c ../../src/cfront.h ../../src/size.h
	$(CC)  $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/simpl.c

simpl2..c: ../../src/simpl2.c ../../src/cfront.h ../../src/size.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/simpl2.c

size..c: ../../src/size.c ../../src/cfront.h ../../src/size.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/size.c

table..c: ../../src/table.c ../../src/cfront.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/table.c

template..c: ../../src/template.c ../../src/cfront.h ../../src/template.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/template.c

tree_copy..c: ../../src/tree_copy.c ../../src/cfront.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/tree_copy.c

tree_walk..c: ../../src/tree_walk.c ../../src/cfront.h ../../src/node_classes.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/tree_walk.c

typ..c: ../../src/typ2.c ../../src/cfront.h ../../src/size.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/typ.c

typ2..c: ../../src/typ2.c ../../src/cfront.h ../../src/size.h
	$(CC) $(FILLDEF) $(FILLUNDEF) $(SZAL) -Fc -..c ../../src/typ2.c

y.tab..c: y.tab.c ../../src/cfront.h ../../src/size.h ../../src/template.h
	$(CC) $(FILLDEF) $(FILLUNDEF) -DGRAM $(SZAL) -Fc -..c ../../src/y.tab.c
