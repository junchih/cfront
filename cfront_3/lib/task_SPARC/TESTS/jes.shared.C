#include <task.h>

/* non-trivial test example:
	make a set of tasks which pass an object round between themselves
	use printf to indicate progress
	WARNING: this program sets up an infinite loop
*/

void
dirty()
{
	int	i, j, k;
	i = -1; j = -2; k = -3;
}

struct pc : task {
	pc(char*, qtail*, qhead*, int);
};

pc::pc(char* n, qtail* t, qhead* h, int s_or_d) :task(n, s_or_d)
{
	printf("new pc(%s,%d,%d,%s)\n", n, t, h,
			s_or_d==DEDICATED ? "DEDICATED" : "SHARED");
	if (*n < 'a'+ 5) {
		char*	c = new char[2]; c[0] = *n + 1; c[1] = '\0';
		qtail*	qt = new qtail;
		pc*	next = new pc(c, t, qt->head(),
				s_or_d == SHARED ? DEDICATED : SHARED);
		t = qt;
	} else {
		printf("%s: here we go\n", n);
		t->put(new object);
	}
	for (;;) {
		object* p = h->get();
		dirty();
		printf("task %s\n",n);
		t->put(p);
	}
}

main()
{
	qhead* hh = new qhead;
	qtail* t = hh->tail();
	qhead* h;

	printf("main\n");

	char* n = "a"; // make a one letter task name

	h = new qhead;
	new pc(n,t,h, SHARED);
	printf("main()'s loop\n");
	t = h->tail();
	for (;;) {
		object* p = hh->get();
		printf("main task\n");
		t->put(p);
	}
}

