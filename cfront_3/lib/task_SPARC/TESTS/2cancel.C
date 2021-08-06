// This is the bug reported by Martin Carrol in mdc.2cancel.C, with 
// extraneous text removed.  This should print "passed" twice.
#include <task.h>
#include <iostream.h>

class mytask : public task 
{
public:
	mytask();
};

mytask::mytask()
{
	resultis(0);
}

main()
{
	mytask t;	// t runs and terminates here
			// cancel is called, and it frees space used
			// for t's stack
	object *o = new object;	// newly freed space for t's stack is reused
				// here for object
	o->remember(&t);	// remember TERMINATED task--this has been
				// changed since 2.1 to be a silent no-op
	t.cancel(0);		// second call of t->cancel; in post-2.1
				// releases, this is innocuous.
	o->forget(&t);  // dumped core on sun and 3b2 in 2.1 and earlier
			// releases because o had been corrupted by cancel.
	delete o;
	printf("passed\npassed\n");
	thistask->resultis(0);
}
