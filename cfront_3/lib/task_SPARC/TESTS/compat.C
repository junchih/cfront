#if defined(TEST_TASK)
#include "test_task.h"
#else
#include <task.h>
#endif

/*
 * Compat.C
 * based on triv.C with additions to test compatibility of various task 
 * changes with 1.2 constructs, and to test various functions.
 * Specifically:
 * 	-calls task::print(VERBOSE|CHAIN|STACK)
 * 	 also uses function TOP() from hw_stack.c, which is not part
 * 	 of public interface of task library; it is used to provide
 * 	 point of reference to check output from print(STACK).
 *	-sets _hwm.
 *	-calls o_type() and makes sure users can #define new obj_types
 *	 that are not part of enum defined in task.h.
 *	-passes msg objects through queue instead of plain objects.
 *	-cycles through task_chain calling rd_state() for all tasks.
 *	-test_task.h for developer use, to try out header file changes.
 */


#define MSG2	8

const int NTASKS = 2;
const int MAX_CYCLES = 5;

class msg : public object {
	int	data;
public:
		msg()	{ data = 0; }
		msg(int i)	{ data = i; }
};

class msg2 : public object {
	int	data;
public:
		msg2()	{ data = 0; }
		msg2(int i)	{ data = i; }
	objtype	o_type()	{ return (objtype) MSG2; }
};

#include "hw_stack.h"

int*
call_frames(int i)
{
	int* sp;
	if (--i > 0) {
		sp = call_frames(i);
	} else {
		//printf("call_frames(%d):  last one, sp == %x\n", i+1, TOP());
		sp = TOP();
	}
	return sp;
}

struct pc : task {
        pc(char*, qtail*, qhead*);
};

pc::pc(char* n, qtail* t, qhead* h) : task(n)
{
        printf("new pc(%s)\n",n);

        for (int i = 0; i < MAX_CYCLES; i++) {
                msg* p = (msg*) h->get();
                printf("task %s\n",n);
                t->put(p);
        }
	printf("task %s: done.\n", n);
	int* sp = call_frames(25);
	printf("call_frames(25) returned %x\n", sp);
	this->print(VERBOSE|CHAIN|STACK);
	resultis(0);
}
extern char* state_string(sched::statetype);


main()
{
_hwm = 1;
        qhead* hh = new qhead;
        qtail* t = hh->tail();		// hh and t refer to same queue.
        qhead* h;

        printf("main\n");

        for (int i=0; i<NTASKS; i++) {
                char* n = new char[2];
                n[0] = 'a'+i;
                n[1] = 0;

                h = new qhead;
                new pc(n,t,h);
                printf("main()'s loop\n");
                t = h->tail();
        }

        new pc("first pc",t,hh);
        printf("main: here we go\n");
	task* tp;
	for(tp = (task*)task_chain; tp != 0; tp = tp->t_next) {
		sched::statetype j = tp->rdstate();
		printf("task %x (%s), state = %d, state_string = %s\n", tp, tp->t_name, j, state_string(j));
	}
        t->put(new msg);
	msg2 *tmpmsg2 = new msg2;
	object *tmpobj = new object;
	if ((tmpmsg2->o_type() != MSG2) || (tmpobj->o_type() != object::OBJECT)) {
		printf("Something wrong with o_type() for objects\n");
	}
        printf("main: exit\n");
	thistask->resultis(0);
}

