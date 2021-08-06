// This is the bug reported by Martin Carroll in mdc.delTERM.C, with
// extraneous business of double cancel's removed, and longer remember
// lists added, but this one is expected to generate a runtime error,
// unlike delTERM.C.
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
mytask t2;

void f()
{
	object o;
	o.remember(&t);
	o.remember(&t2);
	o.remember(&t);
	t.cancel(0);
	// when o is deleted here, it is remembering 3 tasks, of which 
	// 2 (both t) are TERMINATED, but 1 (t2) isn't, so there will be
	// a runtime error.
}
main()
{
	f();
	thistask->resultis(0);
}
