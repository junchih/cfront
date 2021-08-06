/**************************************************************************
			Copyright (c) 1984 AT&T
	  		  All Rights Reserved  	

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T
	
	The copyright notice above does not evidence any   	
	actual or intended publication of such source code.

*****************************************************************************/
#include <task.h>

/*
 * triverand.C
 * Derived from triv.C, which is taken from "Appendix:  A Program Using Tasks"
 * section of Stroustrup/Shopiro coroutine memo, Release Notes pp 13-23 - 13-24.
 * trivial task example:
 *	Makes a set of tasks which pass an object round between themselves.
 *	Each task gets an object from the head of one queue, and puts
 *	the object on the tail of another queue.
 *	Main creates each task, then puts the object on a queue.
 *	Each task quits after getting the object MAX_CYCLES times.
 *	The object is of a derived class which uses class erand and the
 *	draw functions.
 */

const int NTASKS = 1;
const int MAX_CYCLES = 5;

class  rando: public object {
public:
	erand*	erandp;
	int randn;
	rando(int n=10);
};

rando::rando(int n)
{
	erandp = new erand(n);
	randn = erandp->draw();
}

struct pc : task {				// derive a class from task
        pc(char*, qtail*, qhead*);		// task is not intended to
};						// be used directly

pc::pc(char* n, qtail* t, qhead* h) :task(n)	// task body serves as
{						// "main" program for task
        printf("new pc(%s)\n",n);

        for (int i = 0; i < MAX_CYCLES; i++) {
                rando* p = (rando*) h->get();
                printf("task %s\n",n);
		printf("got p->randn = %d\n", p->randn);
		p->randn = p->erandp->draw();
		printf("changed values: p->randn = %d\n", p->randn);
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
        qtail* t = hh->tail();		// hh and t refer to same queue.
        qhead* h;

        printf("main\n");

        for (int i=0; i<NTASKS; i++) {
                char* n = new char[2];	// make a one letter task name
                n[0] = 'a'+i;
                n[1] = 0;

                h = new qhead;
                new pc(n,t,h);		// create a new task and start execution
                printf("main()'s loop\n");
                t = h->tail();
        }

        new pc("first pc",t,hh);	// create another new task
        printf("main: here we go\n");
        t->put(new rando);		// put the object on a queue
        printf("main: exit\n");
	thistask->resultis(0);		// main is a task too; it must also
					// end with resultis (to allow any
					// remaining tasks to run, otherwise
					// the whole process would exit).
}

