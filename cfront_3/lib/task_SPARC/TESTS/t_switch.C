#include <task.h>

/*
 * t_switch.C
 * Example taken from "Appendix:  Example Programs" section of Shopiro
 * Extending the C++ Tasks System memo, Release Notes p 13-40.
 * Task example using semaphores to switch between 2 tasks.
 * Can be used to time task switches.
 */

#define K 10000

class Semaphore : public object {
	int	sigs;
public:
		Semaphore(int i =0) { sigs = i; }
	int	pending();
	void	wait();
	void	signal() { if (sigs++ == 0) alert(); }
};

void
Semaphore::wait()
{
	for (;;) {
		if (--sigs >= 0)
			return;
		sigs++;
		this_task()->sleep(this);
	}
}

int
Semaphore::pending()
{
	return sigs <= 0;
}

class Child : public task
{
public:
		Child();
};

Semaphore sema1;	// for signals from main to Child
Semaphore sema2;	// for signals from Child to main

Child::Child()
: task("Child")
{
	for (register int n = K / 2; n--; ) {
		sema1.wait();	// wait for a signal from main
		sema2.signal();	// send it back
	}
	resultis(0);
}

main()
{
	new Child;
	sema1.signal();		// send the first signal
	for (register int n = K / 2; n--; ) {
		sema2.wait();	// wait for a signal from Child
		sema1.signal();	// send it back
	}
	thistask->resultis(0);
}

