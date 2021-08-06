#include <task.h>

/*
 * misc.C
 * Miscellaneous short examples from Stroustrup/Shopiro coroutine memo,
 * Release Notes pp 13-8 - 13-15.
 * From Sections:  "More about Queues:  Mode and Size," "More About Tasks,"
 * (ctor args, task_chain, print), "Waiting," "System Time and Timers,"
 * "More about Queues:  Cutting and Splicing" (task deleting itself).
 */


typedef enum { PLUS, MINUS, VALUE, ERROR } op_type;
typedef enum { NORMAL, CANCELLED, SUCCESS, ERR } result_type;

class Server : public task
{
public:
	Server(char*, qhead *);
};

Server::Server(char* name, qhead* in)
: task(name)
{
	if(name) {	// dummy conditional to prevent the C compiler from
			// inlining this function.
		printf("Server::Server()\n");
	} else {
		printf("Server::Server()\n");
	}
	resultis(NORMAL);
}

class dummy_task : public task
{
public:
	dummy_task(char*);
};

dummy_task::dummy_task(char* name) : task(name)
{
	if(name) {	// dummy conditional to prevent this function from
			// being inlined by the C compiler
		printf("dummy_task::dummy_task(%s) created\n", name);
	} else {
		printf("dummy_task::dummy_task(%s) created\n", name);
	}
	for(;;) {
		delay(30);
	}
	resultis(NORMAL);
}

class dummy_task2 : public task
{
public:
	dummy_task2(char*);
};

dummy_task2::dummy_task2(char* name) : task(name)
{
	printf("dummy_task2::dummy_task2(%s) created\n", name);
	delay(10);
	printf("dummy_task2:  cancelling myself\n");
	// 6. MORE ABOUT QUEUES:  CUTTING AND SPLICING
	// near the end--this is the sequence of operations to allow
	// a task to remove itself without a trace.
	cancel(CANCELLED);
	delete this;		// calls the scheduler
}

const int BUFSIZE = 128;
main()
{
	// 3.2 More about queues:  mode and size
	qhead	Q1(ZMODE, 10);
	qhead*	QP2 = new qhead(EMODE, 64*BUFSIZE);
	qhead	qh(WMODE, 10);
	qhead*	q2 = new qhead(WMODE, 10);
	qtail*	qt = qh.tail();
	qtail*	qt2 = q2->tail();
	qt->put(new object);
	object*	oo = qh.get();
	printf("object oo = HEX_ADDRESS\n");
	qh.putback(oo);
	oo = qh.get();
	printf("object oo = HEX_ADDRESS\n");

	// 4. MORE ABOUT TASKS
	qhead*	qhp = &qh;
//  Can't create SHARED task object on the stack.
//	Server	my_name_is_fred("fred", qhp);
	Server*	my_name_is_fred = new Server("fred", qhp);

	task*	d1p = new dummy_task("d1p");
	task*	d2p = new dummy_task2("d2p");
	task*	t;
	printf("main:  task_chain so far:\n");
	for (t = task_chain; t; t=t->t_next) {
		t->print(0);
	}

	// 5. WAITING
	task* taskp = my_name_is_fred;
	thistask->wait(taskp);
	qt2->put(oo);
	short	who = thistask->waitlist(qhp, q2, 0);
	printf("main:  who (caused return from waitlist) = %d\n", who);
	object*	vec[3];
	vec[0] = qhp;
	vec[1] = q2;
	who = thistask->waitvec(vec);
	printf("main:  who (caused return from waitvec) = %d\n", who);

	//5.1 System Time and Timers
	long n = 10;
	long time = ((sched*)0)->get_clock();
	thistask->delay(n);
	long actual_delay = ((sched*)0)->get_clock() - time;
	printf("time = %d, n = %d, actual_delay = %d\n", time, n, actual_delay);

	int	time_left = d1p->preempt();
	printf("time_left = %d\n", time_left);
	d1p->delay(time_left + 10);

	timer*	tt = new timer(15);
	short	res = thistask->waitlist(d1p, tt, 0);
	switch(res) {
	case 0:
		printf("normal completion of io\n");
		break;
	case 1:
		printf("time out occurred:  clock = %d\n", ((sched*)0)->get_clock());
		break;
	default:
		printf("IMPOSSIBLE\n");
		break;
	}

	for (t = task_chain; t; t=t->t_next) {
		if (t->rdstate() != sched::TERMINATED) {
			printf("About to cancel %s\n", t->t_name);
			t->cancel(CANCELLED);
		} else {
			printf("%s already terminated with result = %d\n", t->t_name, t->result());
		}
	}
	thistask->resultis(NORMAL);
}
