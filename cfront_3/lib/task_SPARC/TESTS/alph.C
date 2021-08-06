/*ident	"@(#)ctrans:demo/task/alph.C	1.1" */
/**************************************************************************
			Copyright (c) 1984 AT&T
	  		  All Rights Reserved  	

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T
	
	The copyright notice above does not evidence any   	
	actual or intended publication of such source code.

*****************************************************************************/
/*
 * alph.C
 * Semaphores taken from Shopiro "Extending the C++ Task System" memo
 * Release Notes pp 13-28 - 13-29.
 * Demonstration of two tasks communicating via semaphores.
 * Defines objects (semaphores) that tasks can wait for.
 */

#include <task.h>
#define K 10

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

class Test : public task
{
public:
		Test(int);
};

Semaphore* sema[2];

Test::Test(int i)
: task(i ? "Alphonse" : "Gaston")
{
	for (register int n = K / 2; n--; ) {
		sema[!i]->wait();
		sema[i]->signal();
		printf("%s: %d\n", i ? "Alphonse" : "Gaston", n);
	}
	resultis(0);	// always terminate with resultis;
			// "return" or coming to end of function is undefined.
}

main()
{
	sema[0] = new Semaphore(1);
	sema[1] = new Semaphore;
	new Test(0);	// create "Gaston" task; switch to it
	new Test(1);	// create "Alphonse" task; switch to it
	((object*)0)->this_task()->resultis(0); // terminate main task
}
