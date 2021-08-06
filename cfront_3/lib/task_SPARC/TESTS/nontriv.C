#include <task.h>
#include <stdlib.h>

/*
 * nontriv.C
 * Modified example from "Appendix:  A Program Using Tasks" section of
 * Stroustrup/Shopiro coroutine memo, Release Notes pp 13-23 - 13-24.
 * non-trivial test example:
 *	Makes a set of tasks which pass an object round between themselves.
 *	Each task but the last creates the next task.
 *	Each task quits after getting the object MAX_CYCLES times.
 */

const int NTASKS = 1;
const int MAX_CYCLES = 5;

struct pc : task {
        pc(char*, qtail*, qhead*);
};

pc::pc(char* n, qtail* t, qhead* h) : task(n)
{
	register pc*	saved_this = this;
	register int i = *n;
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
	if (this_task() != this) {
		printf("%s: thistask=%d, this=%d\n", n, this_task(), this);
		abort();
	}
        for (int cycles = 0; cycles < MAX_CYCLES; cycles++) {
		if (this_task() != this || this != saved_this || i != *n) {
			printf("%s: thistask=%d, this=%d, line %d\n", n, this_task(), this, __LINE__);
			abort();
		}
                object* p = h->get();
                printf("task %s\n",n);
		if (this_task() != this || this != saved_this) {
			printf("%s: thistask=%d, this=%d, line %d\n", n, this_task(), this, __LINE__);
			abort();
		}
                t->put(p);
        }
	printf("task %s: done.\n", n);
	resultis(0);
}

void
done_fct()
{
	printf("all done\n");
}

main()
{
	register int i = 3;
        qhead* hh = new qhead;
        qtail* t = hh->tail();
        qhead* h;
	sched::exit_fct = done_fct;

        printf("main\n");

	char* n = "a"; // make a one letter task name

	h = new qhead;
	new pc(n,t,h);
	printf("main()'s loop\n");
	t = h->tail();
        for (int cycles = 0; cycles < MAX_CYCLES; cycles++) {
                object* p = hh->get();
		if (i != 3) {
			printf("main: reg i should == 3, instead == %d\n", i);
			exit(1);
		}
                printf("main task\n");
                t->put(p);
        }
	printf("main task: done.\n", n);
	//((object*)0)->this_task()->resultis(0);
	thistask->resultis(0);
}

