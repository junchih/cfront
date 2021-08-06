/*ident	"@(#)cls4:demo/task/sigtest.C	1.1" */
/*******************************************************************************
 
C++ source for the C++ Language System, Release 3.0.  This product
is a new release of the original cfront developed in the computer
science research center of AT&T Bell Laboratories.

Copyright (c) 1991 AT&T and UNIX System Laboratories, Inc.
Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.

THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
Laboratories, Inc.  The copyright notice above does not evidence
any actual or intended publication of such source code.

*******************************************************************************/
#include <task.h>
#include <stdio.h>
#include <osfcn.h>

/* Task example showing 2 tasks communicating with semaphores and signals.
 * Uses the new signal-handling mechanisms in the task library: class
 * Interrupt_handler and the virtual interrupt() function.
 */

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

Semaphore* sema;

/* Classes derived from Interrupt_handler are objects that
 * tasks can wait for.  Objects of type Sig_handler will be alerted when
 * signals of the denoted number come in.
 */
class Sig_handler : public Interrupt_handler {
	int	sig_id;
public:
		Sig_handler(int sigid) : Interrupt_handler(sigid)
				{ sig_id = sigid; }
		~Sig_handler() {};
	void	interrupt();	// Interrupt_handler::interrupt is virtual
};

/* The interrupt function will be called immediately when
 * a signal is received.  Use it to do time-critical processing.
 */
void
Sig_handler::interrupt()
{
	printf("Sig_handler::interrupt()  got signal %d\n", sig_id);
}

class Sig_task : public task
{
	int	nsigs;
public:
		Sig_task(char*, int);
};

const int	MAX_SIGS = 5;

Sig_task::Sig_task(char* n, int i)
: task(n)
{
	nsigs = 0;
	// Create handler to catch signal i's
	Sig_handler* sig_hand_p = new Sig_handler(i);
	while (nsigs < MAX_SIGS) {
		wait(sig_hand_p); // call task::wait(object*) to block;
				  // waiting for a signal i
		printf("Sig_task %s, woke up for signal %d.\n", n, i);
		nsigs++;
		sema->signal();	// let Sig_sender know we're ready for another
	}
	printf("Sig_task %s:  all done.\n", n);
	delete sig_hand_p;	// clean up
	resultis(0);		// always end task constructor bodies with
				// resultis.
}

class Sig_sender : public task {
	int	nsigs;
public:
		Sig_sender(char*, int);
};

Sig_sender::Sig_sender(char* n, int i) : task(n)
{
	nsigs = 0;
	while (nsigs < MAX_SIGS) {
		printf("Sig_sender %s:  about to send signal %d.\n", n, i);
		kill(getpid(), i);	// send signal i to this process
		nsigs++;
		sema->wait();		// block so Sig_task has a chance
					// to handle the signal.
	}
	printf("Sig_sender %s:  all done.\n", n);
	resultis(0);
}

main()
{
	sema = new Semaphore; 			   // create a Semaphore
	new Sig_task("sigusr1 task", SIGUSR1);	   // create task; switch to it
	new Sig_sender("sigusr1 sender", SIGUSR1); // create task; switch to it
	printf("main:  all done.\n");
	thistask->resultis(0);		// main is a task too; must end it with
					// resultis (to allow remaining tasks
					// to run).
}
