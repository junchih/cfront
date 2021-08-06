/*ident	"@(#)cls4:demo/task/shared.C	1.1" */
/*******************************************************************************
 
C++ source for the C++ Language System, Release 3.0.  This product
is a new release of the original cfront developed in the computer
science research center of AT&T Bell Laboratories.

Copyright (c) 1991 AT&T and UNIX System Laboratories, Inc.
Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.

THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
Laboratories, Inc.  The copyright notice above does not evidence
any actual or intended publication of such source code.

*******************************************************************************/
#include <task.h>

/* non-trivial task example:
	Make a set of SHARED tasks
	which pass an object round between themselves.
	Each task but the last creates the next task.
	Each task gets an object from the head of one queue, and puts
	the object on the tail of another queue.
	Each task quits after getting the object MAX_CYCLES times.
*/

const int NTASKS = 1;
const int MAX_CYCLES = 5;

struct pc : task {				// derive a class from task
        pc(char*, qtail*, qhead*);		// task is not intended to
};						// be used directly

pc::pc(char* n, qtail* t, qhead* h) :task(n, SHARED) // task body serves as
{						// "main" program for task
	int cycles;

        printf("new pc(%s)\n",n);
	if (*n < 'a'+ NTASKS) {
		char*	c = new char[2]; c[0] = *n + 1; c[1] = '\0';
		qtail*	qt = new qtail;
		pc*	next = new pc(c, t, qt->head());
		t = qt;
	} else {
		printf("%s: here we go\n", n);
		t->put(new object);
	}
        for (cycles = 0; cycles < MAX_CYCLES; cycles++) {
		object* p = h->get();
		printf("task %s\n",n);
		t->put(p);
	}
	printf("task %s: done.\n", n);
	resultis(0);		// Always end task constructors with resultis.
				// Behavior of those using return or running
				// off the end of the function is undefined.
				// Alternatively, use an infinite loop in
				// constructor body.
}

main()
{
	qhead* hh = new qhead;
	qtail* t = hh->tail();
	qhead* h;
	int cycles;

	printf("main\n");

	char* n = "a"; // make a one letter task name

	h = new qhead;
	new pc(n,t,h);
	printf("main()'s loop\n");
	t = h->tail();
        for (cycles = 0; cycles < MAX_CYCLES; cycles++) {
		object* p = hh->get();
		printf("main task\n");
		t->put(p);
	}
	printf("main task: done.\n", n);
	thistask->resultis(0);		// main is a task too; it must also
					// end with resultis (to allow any
					// remaining tasks to run, otherwise
					// the whole process would exit).
}

