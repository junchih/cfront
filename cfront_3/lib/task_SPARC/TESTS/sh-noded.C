#include <task.h>

/* non-trivial test example:
	make a set of tasks which pass an object round between themselves
	use printf to indicate progress
	This one is like sh-ded.C but it only creates SHARED tasks
*/
const int NTASKS = 25;	// Really, n tasks = NTASKS + a + main
const int MAX_CYCLES = 25;
const int PRINT_MAX = 5;     // Don't print progress if MAX_CYCLES > PRINT_MAX

void
dirty()
{
	int	i, j, k;
	i = -1; j = -2; k = -3;
}

struct pc : task {
	pc(char*, qtail*, qhead*, modetype);
};

pc::pc(char* n, qtail* t, qhead* h, modetype s_or_d) :task(n, s_or_d)
{
	//printf("new pc(%s,%d,%d,%s)\n", n, t, h,
	printf("new pc(%s,%s)\n", n,
			s_or_d==DEDICATED ? "DEDICATED" : "SHARED");
	if (*n < 'a'+ NTASKS) {
		char*	c = new char[2]; c[0] = *n + 1; c[1] = '\0';
		qtail*	qt = new qtail;
		pc*	next = new pc(c, t, qt->head(),
				SHARED);
		t = qt;
	} else {
		printf("%s: here we go\n", n);
		t->put(new object);
	}
        for (int cycles = 0; cycles < MAX_CYCLES; cycles++) {
		object* p = h->get();
		dirty();
		if (MAX_CYCLES < PRINT_MAX) {
			printf("task %s\n",n);
		}
		t->put(p);
	}
	printf("task %s: done.\n", n);
	resultis(0);
}

main()
{
	qhead* hh = new qhead;
	qtail* t = hh->tail();
	qhead* h;

	printf("main\n");

	char* n = "a"; // make a one letter task name

	h = new qhead;
	new pc(n,t,h, task::SHARED);	printf("main()'s loop\n");
	t = h->tail();
        for (int cycles = 0; cycles < MAX_CYCLES; cycles++) {
		object* p = hh->get();
		if (MAX_CYCLES < PRINT_MAX) {
			printf("main task\n");
		}
		t->put(p);
	}
	printf("main task: done.\n", n);
	thistask->resultis(0);
}

