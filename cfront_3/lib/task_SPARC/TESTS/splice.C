#include <task.h>

/*
 * Tasking program to test fix to bug in qhead::splice that occurred
 * when a splice occurred to a queue on which another task was blocked.
 *
 * Main sets up 2 queues:  Q1h-Q1t and Q2h-Q2t.  Task T A gets from
 * Q1h and puts to Q2t.  It attempts to put QMAX+1 objects on the Q2t,
 * and blocks.  Task TT B puts QMAX objects on Q1t, then splices the
 * 2 queues, forming one with Q1h as the head and Q2t as the tail.
 * Task TT B gets MAX+1 objects from Q1h, so as to alert Task A that
 * its Q2t->put can complete, and then completes.  Task A runs again,
 * and gets the rest of the objects off the queue and quits.
 *
 * EXPECTED OUTPUT:
 * Output should show Objects 1-11 being put and gotten from the queue
 * (they won't necessarily be in sequence, but each put should have a matching
 * get) and main, B, and A should all announce that they're done.
 */

const int QMAX = 5;

class O : public object {	// sequentially numbered objects
	static int Ocount;
	int id;
public:
			O()		{ id = ++Ocount; }
	int		get_id()	{ return id; }
	static int	get_Ocount()	{ return Ocount; }
};

int O::Ocount;

class T : public task {
public:
        T(char*, qtail*, qhead*);
};

T::T(char* n, qtail* t, qhead* h) :task(n)
{
	O *Op;
        printf("new T(%s)\n",n);
	for (int i = 0; i <= QMAX; i++) {
				// put more Os than Qmax to make T block
		Op = new O;
		t->put(Op);
		printf("T %s:  put O %d\n", n, Op->get_id());
	}
	while ( h->rdcount() > 0 ) {
		Op = (O*) h->get();
		printf("T %s:  got O %d\n", n, Op->get_id());
	}

	printf("T %s: done.\n", n);
	resultis(0);
}

class TT : public task {
public:
        TT(char*, qtail*, qhead*);
};

TT::TT(char* n, qtail* t, qhead* h) :task(n)
{
        printf("new TT(%s)\n",n);
	O *Op;
	for (int i = 0; i < QMAX; i++) {	// don't overflow the queue
		Op = new O;
		t->put(Op);
		printf("TT %s:  put O %d\n", n, Op->get_id());
	}
	qhead *h2 = t->head();	// h is about to be deleted in the splice
	h->splice(t);	// only one queue now

	while(h2->rdcount() >= QMAX) {
		Op = (O*) h2->get();	
		printf("TT %s:  got O %d\n", n, Op->get_id());
	}

	printf("TT %s: done.\n", n);
	resultis(0);
}

main()
{
	qhead *Q1h = new qhead(WMODE, QMAX);
	qtail *Q1t = Q1h->tail();
	qhead *Q2h = new qhead(WMODE, QMAX);
	qtail *Q2t = Q2h->tail();

	T *TA = new T("A", Q2t, Q1h);
	TT *TB = new TT("B", Q1t, Q2h);

	printf("main: exit\n");
	thistask->resultis(0);
}

