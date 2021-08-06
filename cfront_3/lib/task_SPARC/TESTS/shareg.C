#include <task.h>
#include <stdlib.h>

/*
 * shareg.C
 * Modified example from "Appendix:  A Program Using Tasks" section of
 * Stroustrup/Shopiro coroutine memo, Release Notes pp 13-23 - 13-24.
 * non-trivial test example:
 *	Makes a set of SHARED tasks which pass an object around.
 *	Each task but the last creates the next task.
 *	Each task gets an object from the head of one queue, and puts
 *	the object on the tail of another queue.
 *	Each task quits after getting the object MAX_CYCLES times.
 *	Each task uses lots of registers that must be preserved across a switch.
 */

const int NTASKS = 1;
const int MAX_CYCLES = 5;

void
dirty()
{
	register int i, j, k, l, m, z;
	i = -1; j = -2; k = -3; l = -4; m = -5; z = -6;
}

struct pc : task {
	pc(char*, qtail*, qhead*);
};

pc::pc(char* n, qtail* t, qhead* h) :task(n, SHARED)
{
	register int	i, j, k, l, m, z;
	i = *n + 11; j = *n + 12; k = *n + 13;
	l = *n + 14; m = *n + 15; z = *n + 16;
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
	if (i != *n + 11 || j != *n + 12 || k != *n + 13 ||
	    l != *n + 14 || m != *n + 15 || z != *n + 16) {
		printf("pc:  lost regs! i==%d, j==%d, k==%d, l==%d, m==%d, z==%d\n", i, j, k, l, m, z);
		printf("vals should be: i: %d, j: %d, k: %d, l: %d, m: %d, z: %d\n", *n + 11, *n + 12, *n + 13, *n + 14, *n + 15, *n + 16);
		abort();
	}
        for (int cycles = 0; cycles < MAX_CYCLES; cycles++) {
		object* p = h->get();
		dirty();
		printf("task %s\n",n);
		t->put(p);
	}
	printf("task %s: done.\n", n);
	resultis(0);
}

main()
{
	register int	i, j, k, l, m, z;
	qhead* hh = new qhead;
	qtail* t = hh->tail();
	qhead* h;

	printf("main\n");

	char* n = "a"; // make a one letter task name
	i = *n + 1; j = *n + 2; k = *n + 3;
	l = *n + 4; m = *n + 5; z = *n + 6;

	h = new qhead;
	new pc(n,t,h);
	printf("main()'s loop\n");
	if (i != *n + 1 || j != *n + 2 || k != *n + 3 ||
	    l != *n + 4 || m != *n + 5 || z != *n + 6) {
		printf("main:  lost regs! i==%d, j==%d, k==%d, l==%d, m==%d, z==%d\n", i, j, k, l, m, z);
		printf("values should be: i: %d, j: %d, k: %d, l: %d, m: %d, z: %d\n", *n + 1, *n + 2, *n + 3, *n + 4, *n + 5, *n + 6);
		abort();
	}
	t = h->tail();
        for (register int cycles = 0; cycles < MAX_CYCLES; cycles++) {
		object* p = hh->get();
		if (i != *n + 1 || j != *n + 2 || k != *n + 3 ||
		    l != *n + 4 || m != *n + 5 || z != *n + 6) {
			printf("main (after get):  lost regs! i==%d, j==%d, k==%d, l==%d, m==%d, z==%d\n", i, j, k, l, m, z);
			printf("values should be:             i: %d, j: %d, k: %d, l: %d, m: %d, z: %d\n", *n + 1, *n + 2, *n + 3, *n + 4, *n + 5, *n + 6);
			abort();
		}
		printf("main task\n");
		t->put(p);
	}
	printf("main task: done.\n", n);
	//((object*)0)->this_task()->resultis(0);
	thistask->resultis(0);
}
