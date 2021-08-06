// This is the bug reported by Martin Carroll in mdc.delTERM.C, with
// extraneous business of double cancel's removed, and longer remember
// lists added.
#include <stdio.h>
#include <task.h>

class mytask : public task 
{
public:
	mytask();
};

mytask::mytask()
{
	sleep();
	resultis(0);
}

mytask t;

void f()
{
	object o;
	o.remember(&t);
	o.remember(&t);
	o.remember(&t);
	t.cancel(0);
	// when o is deleted here, it is remembering 3 tasks (all t), which
	// are all TERMINATED, so there should be no error.
}
main()
{
	f();
	printf("passed\npassed\n");
	thistask->resultis(0);
}
