#ident	"@(#)cop4:sparc_task/mk/makefile	1.2"
# Sun @(#)makefile 1.7 90/07/27 SMI
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
LIB		=	lib
O_TASK		=	$(LIB)/erand.o $(LIB)/event.o $(LIB)/fudge.o \
			$(LIB)/hw_stack.o $(LIB)/obj.o $(LIB)/qhead.o \
			$(LIB)/qtail.o $(LIB)/sched.o $(LIB)/sim.o \
			$(LIB)/swap.o $(LIB)/swap_supp.o $(LIB)/task.o \
			$(LIB)/timer.o
OFILES	=	$(O_TASK)
#CC	=	cc
#CCC	=	CC
CC	=	CC
CCFLAGS	=	-g
SRC=../task
MACH=sparc
BSD=1

.INIT:
	@if [ \! -d $(LIB) ]; then		\
		mkdir $(LIB);			\
	fi

libtask.a:	$(OFILES)
#		cp *.o lib/.
		ar r libtask.a $?
		if test "$(BSD)" ; then ranlib libtask.a; fi

$(LIB)/erand.o:	$(SRC)/erand.c  $(SRC)/hw_stack.h
	$(CC) $(CCFLAGS) -I$(SRC) -o $@ -c $(SRC)/erand.c

$(LIB)/event.o:	$(SRC)/event.c
	$(CC) $(CCFLAGS) -I$(SRC) -o $@ -c $(SRC)/event.c

$(LIB)/fudge.o:	$(SRC)/hw_stack.h $(SRC)/fudge.c
	$(CC) $(CCFLAGS) -I$(SRC) -o $@ -c $(SRC)/fudge.c

$(SRC)/fudge.c:	$(SRC)/fudge.c.$(MACH)
	@rm -f $(SRC)/fudge.c
	cp $(SRC)/fudge.c.$(MACH) $(SRC)/fudge.c

$(SRC)/swap.s:	$(SRC)/swap.s.$(MACH)
	@rm -f $(SRC)/swap.s
	cc $(CCFLAGS) -I$(SRC) -E $(SRC)/swap.s.$(MACH) > $(SRC)/swap.s
#	cp $(SRC)/swap.s.$(MACH) $(SRC)/swap.s

$(LIB)/hw_stack.o:	$(SRC)/hw_stack.h $(SRC)/hw_stack.c
	$(CC) $(CCFLAGS) -I$(SRC) -o $@ -c $(SRC)/hw_stack.c

$(LIB)/obj.o:		$(SRC)/obj.c
	$(CC) $(CCFLAGS) -I$(SRC) -o $@ -c $(SRC)/obj.c

$(LIB)/qhead.o:	$(SRC)/qhead.c
	$(CC) $(CCFLAGS) -I$(SRC) -o $@ -c $(SRC)/qhead.c

$(LIB)/qtail.o:	$(SRC)/qtail.c
	$(CC) $(CCFLAGS) -I$(SRC) -o $@ -c $(SRC)/qtail.c

$(LIB)/sched.o:	$(SRC)/sched.c
	$(CC) $(CCFLAGS) -I$(SRC) -o $@ -c $(SRC)/sched.c

$(LIB)/sim.o:		$(SRC)/hw_stack.h $(SRC)/sim.c
	$(CC) $(CCFLAGS) -I$(SRC) -o $@ -c $(SRC)/sim.c

$(LIB)/swap.o:		$(SRC)/swap.s
	cc -o $@ -c $(SRC)/swap.s
#	if [ "sparc" = "$(MACH)" ] ; then		\
#	    /bin/rm -f $(SRC)/swap.S ;			\
#	    echo /bin/cp $(SRC)/swap.s $(SRC)/swap.S ;	\
#	    /bin/cp $(SRC)/swap.s $(SRC)/swap.S ;	\
#	    $(CC) $(CCFLAGS) -I$(SRC) -o $@ -c $(SRC)/swap.S; \
#	else						\
#	    echo Just cc it. ;				\
#	    $(CC) $(CCFLAGS) -I$(SRC) -o $@ -c $(SRC)/swap.s; \
#	fi

$(LIB)/swap_supp.o:	$(SRC)/swap_supp.c
	$(CC) $(CCFLAGS) -I$(SRC) -o $@ -c $(SRC)/swap_supp.c

$(LIB)/task.o:		$(SRC)/hw_stack.h $(SRC)/task.c
	$(CC) $(CCFLAGS) -I$(SRC) -o $@ -c $(SRC)/task.c

$(LIB)/timer.o:	$(SRC)/timer.c
	$(CC) $(CCFLAGS) -I$(SRC) -o $@ -c $(SRC)/timer.c
