#include <task.h>

/* trivial task example:
        Make a set of tasks which pass an object round between themselves.
	Each task gets an object from the head of one queue, and puts
	the object on the tail of another queue.
	Main creates each task, then puts the object on a queue.
	Each task quits after getting the object MAX_CYCLES times.
*/

const int NTASKS = 1;
const int MAX_CYCLES = 5;

struct pc : task {				// derive a class from task
        pc(char*, qtail*, qhead*);		// task is not intended to
};						// be used directly

pc::pc(char* n, qtail* t, qhead* h) :task(n)	// task body serves as
{						// "main" program for task
	int me = this->o_type();
        printf("new pc(%s); o_type() = %i\n",n, me);

        for (int i = 0; i < MAX_CYCLES; i++) {
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
	int hhtype = hh->o_type();
        qtail* t = hh->tail();		// hh and t refer to same queue.
	int ttype = t->o_type();
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
        t->put(new object);		// put the object on a queue
	int me = thistask->o_type();
        printf("main: exit\n");
	thistask->resultis(0);		// main is a task too; it must also
					// end with resultis (to allow any
					// remaining tasks to run, otherwise
					// the whole process would exit).
}

