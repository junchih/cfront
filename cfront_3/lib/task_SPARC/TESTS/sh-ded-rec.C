#include <task.h>
#include <stdlib.h>

/* non-trivial test example:
	make a set of tasks which pass an object round between themselves
	use printf to indicate progress
*/
const int HOW_MANY = 4;	// times around the loop (both ways)
const int N_TASKS = 15;	// really n tasks = N_TASKS + 1 + main

void
dirty()
{
	int	i, j, k;
	i = -1; j = -2; k = -3;
}

struct Int_object : object {
	int	count;
		Int_object(int i) : count(i) {}
};

struct pc : task {
	pc(int, qtail*, qhead*, qtail*, qhead*);
};

int
recurse(int i, char* n, qtail* t1, qhead* h1, qtail* t2, qhead* h2)
{
	//printf("task %s in recurse(%d)\n", n, i);
	if (i) {
		if (recurse(i-1, n, t1, h1, t2, h2) != i-1) {
			printf("recursion error!\n");
			exit(1);
		}
	} else {
		object* p = h2->get();
		dirty();
		printf("task %s\n",n);
		t2->put(p);
		p = h1->get();
		printf("%s ksat\n",n);
		t1->put(p);
		return 0;
	}
	return i;
}

pc::pc(int n, qtail* t, qhead* h1, qtail* t2, qhead* h)
: task("pc", n%2 ? DEDICATED : SHARED)
{
	char	name[2];
	name[0] = n + 'a'; name[1] = 0;
	//printf("new pc(%s,%x, h1 = %x, t2 = %x)\n",name,this,h1,t2);
	printf("new pc(%s)\n",name);
	qtail*	t1;
	qhead*	h2;
	if (n < N_TASKS) {
		t1 = new qtail;
		h2 = new qhead;
		pc*	next = new pc(n+1, t, t1->head(), h2->tail(), h);
	} else {
		printf("%s: here we go\n", name);
		t1 = t;
		h2 = h;
		t1->put(new Int_object(HOW_MANY));
	}
	for (;;)
		recurse(n, name, t1, h1, t2, h2);
}

main()
{
	qhead* h1 = new qhead;
	qtail* t2 = new qtail;
	qhead* h = new qhead;
	qtail* t = new qtail;

	printf("main\n");

	new pc(0, h1->tail(), h, t, t2->head());
	qtail* t1 = h->tail();
	qhead* h2 = t->head();
	printf("main()'s loop\n");
	for (;;) {
		Int_object* p = (Int_object*)h1->get();
		printf("main task\n");
		//printf("main task, %x\n", object::this_task());
		t2->put(p);
		p = (Int_object*)h2->get();
		if (--p->count <= 0) {
			printf("done!\n");
			thistask->resultis(0);
		}
		printf("ksat niam\n");
		t1->put(p);
	}
}

