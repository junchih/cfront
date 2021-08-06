#include <task.h>

/*
 * t_create.C
 * Example taken from "Appendix:  Example Programs" section of Shopiro
 * Extending the C++ Tasks System memo, Release Notes p 13-39.
 * Repeatedly creates a task and waits for it to terminate.
 * Can be used to time task creation and termination.
 */


class Child : public task	// user task declaration
{
public:
		Child(int);	// task constructor declaration
};


Child::Child(int i)		// user task constructor is task's "main"
: task("Child")			// argument to base class constructor
{
	resultis(i);		// terminate task execution
				// must NOT return
}

const int K = 66;

main()
{
	for (register int i = K; i--; ) {
		Child* c = new Child(i);	// create a task
		c->result();			// wait for it to terminate
		delete c;			// clean up
	}
	thistask->resultis(0);	// exit from main task
}
