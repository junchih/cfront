#ident	"@(#)cls4:demo/lang/makefile	1.1"
###############################################################################
#			Copyright (c) 1984 AT&T
#	  		  All Rights Reserved  	
#
#	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T
#	
#	The copyright notice above does not evidence any   	
#	actual or intended publication of such source code.
#
###############################################################################
CC=CC
CCFLAGS=-O

templates = array.0.E array.1.E array.2.E array.3.E

virtuals = virtfunc.0.E virtfunc.1.E virtfunc.2.E \
           virtfunc.3.E virtfunc.4.E

virt_base = vb_initial.E vb_virtual.E vb_domin.E

Zooobjs = ZooAnimal.o Bear.o Panda.o

ALL = $(templates) $(virtuals) $(virt_base) new_del.E op_over.E \
	thisPtr.E pClassMem.E static.E hello.E

all: $(ALL) iostreamdir genericdir
	chmod +x ./runtests
	./runtests

hello.E: ./hello.C
	$(CC) $(CCFLAGS) -o ./hello.E ./hello.C

iostreamdir:
	cd ../stream && \
	$(MAKE) CC=$(CC) CCFLAGS="$(CCFLAGS)" run

genericdir:
	cd ../generic && \
	$(MAKE) CC=$(CC) CCFLAGS="$(CCFLAGS)" run

ZooAnimal.o:	ZooAnimal.C ZooAnimal.h 
	$(CC) $(CCFLAGS) -c ZooAnimal.C

Bear.o:	Bear.C Bear.h 
	$(CC) $(CCFLAGS) -c Bear.C

Panda.o:	Panda.C Panda.h 
	$(CC) $(CCFLAGS) -c Panda.C

Screen.o:	Screen.C String.h
	$(CC) $(CCFLAGS) -c Screen.C

String.o:	String.C String.h
	$(CC) $(CCFLAGS) -c String.C

StringList.o:	StringList.C StringList.h
	$(CC) $(CCFLAGS) -c StringList.C

makelist.o: ./makelist.C 		
	$(CC) $(CCFLAGS) -c ./makelist.C 

print.o: ./print.C 		
	$(CC) $(CCFLAGS) -c ./print.C 

virtfunc.0.E:	./virtfunc.0.C $(Zooobjs)
	$(CC) $(CCFLAGS) -o virtfunc.0.E ./virtfunc.0.C $(Zooobjs)

virtfunc.1.E:	./virtfunc.1.C $(Zooobjs)
	$(CC) $(CCFLAGS) -o virtfunc.1.E ./virtfunc.1.C $(Zooobjs)

virtfunc.2.E:	./virtfunc.2.C $(Zooobjs)
	$(CC) $(CCFLAGS) -o virtfunc.2.E ./virtfunc.2.C $(Zooobjs)

virtfunc.3.E:	./virtfunc.3.C $(Zooobjs)
	$(CC) $(CCFLAGS) -o virtfunc.3.E ./virtfunc.3.C $(Zooobjs)

virtfunc.4.E:	./virtfunc.4.C $(Zooobjs) makelist.o print.o
	$(CC) $(CCFLAGS) -o virtfunc.4.E ./virtfunc.4.C $(Zooobjs) makelist.o print.o

op_over.E: String.o StringList.o op_over.C moby_dick
	$(CC) $(CCFLAGS) -o op_over.E ./op_over.C String.o StringList.o

new_del.E: String.o StringList.o new_del.C text
	$(CC) $(CCFLAGS) -o new_del.E ./new_del.C String.o StringList.o

thisPtr.E:	thisPtr.C Screen.o Screen.h
	$(CC) $(CCFLAGS) -o thisPtr.E ./thisPtr.C Screen.o

pClassMem.E:	pClassMem.C Screen.o Screen.h
	$(CC) $(CCFLAGS) -o pClassMem.E ./pClassMem.C Screen.o

static.E:	static.C CoOp.C CoOp.h
	$(CC) $(CCFLAGS) -o static.E ./static.C ./CoOp.C

vb_initial.E:	vb_initial.C
	$(CC) $(CCFLAGS) -o vb_initial.E ./vb_initial.C 

vb_virtual.E:	vb_virtual.C
	$(CC) $(CCFLAGS) -o vb_virtual.E ./vb_virtual.C 

vb_domin.E:	vb_domin.C
	$(CC) $(CCFLAGS) -o vb_domin.E ./vb_domin.C 

array.0.E:	array.0.C Array.h String.o
	$(CC) $(CCFLAGS) -o array.0.E ./array.0.C ./String.o

array.1.E:	array.1.C Array_RC.h 
	$(CC) $(CCFLAGS) -o array.1.E ./array.1.C 

array.2.E:	array.0.C Array_S.h 
	$(CC) $(CCFLAGS) -o array.2.E ./array.2.C ./String.o

array.3.E:	array.0.C Array_RC_S.h String.o
	$(CC) $(CCFLAGS) -o array.3.E ./array.3.C ./String.o

clean:
	rm -f ./*.[oE]
	cd ../stream && $(MAKE) clean
	cd ../generic && $(MAKE) clean
