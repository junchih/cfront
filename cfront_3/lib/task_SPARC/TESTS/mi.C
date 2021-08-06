// Example of using multiple inheritance with the task library.
// Multi-level derivation from class task itself is not allowed
// (for implementation reasons), but multiple inheritance is, so long
// as there is only one level of derivation from class task.

// This example based on triv.C found in demo/task/triv.C and also found
// in the back of the paper by B. Stroustrup & J. Shopiro:  "A Set of
// C++ Classes for Coroutine Style Programming" in the C++ Release 2.0
// Library Manual.

#include <task.h>

const int NTASKS = 2;
const int MAX_CYCLES = 5;

class task_stuff {
	static int ntasks;
	int somedata;
protected:
	task_stuff()	{ if (ntasks) ntasks++;
			  else ntasks= 2;  // main is created with the 1st task
			  somedata = 0; }
public:
	static int get_ntasks()	{ return ntasks; }
	int get_somedata()	{ return somedata; }
	int set_somedata(int i)	{ int d = somedata; somedata= i; return d; }
};

int task_stuff::ntasks;

//Caveat:  members of class task_stuff will not be accessible via the
//thistask pointer, since that is only a pointer to a task.
struct pc : public task, public task_stuff {
        pc(char*, qtail*, qhead*);
};

pc::pc(char* n, qtail* t, qhead* h) :task(n)
{
        printf("new pc(%s)\n",n);
	printf("ntasks = %d\n", get_ntasks());

        for (int i = 0; i < MAX_CYCLES; i++) {
                object* p = h->get();
                printf("task %s\n",n);
                t->put(p);
        }
	printf("task %s: done.\n", n);
	resultis(0);
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

        task *fpc = new pc("first pc",t,hh);	// create another new task
	printf("main: ntasks = %d\n", task_stuff::get_ntasks());
	printf("main: task_chain is:\n");
	for (task* tsk = fpc; tsk; tsk = tsk->t_next) {
		tsk->print(0);
	}
        printf("main: here we go\n");
        t->put(new object);		// put the object on a queue
        printf("main: exit\n");
	thistask->resultis(0);
}

