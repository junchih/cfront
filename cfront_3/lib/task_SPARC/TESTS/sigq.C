#include <task.h>
#include <osfcn.h>

/*
 * sigq.C
 * Example taken from "Real-Time Extensions, Avoiding Interference, Interrupts"
 * section of Shopiro Extending the C++ Tasks System memo,
 * Release Notes pp 13-30 - 13-31.
 * NOTE:  This program is interactive, and cannot be killed with a DEL,
 * requires kill -9 to stop it, so only run it when you can kill it from
 * a different window.
 * Sets up 2 tasks:  Sigint_printer and Sigint_sender.  Sigint_printer
 * sets up an Interrupt_handler and waits for SIGINTS, which are sent by
 * Sigint_sender, and optionally from the terminal.  The Sigint_handler
 * interrupt function puts the interrupts caught onto a rudimentary queue.
 */

const int	QSIZE = 5;
class Sigint_handler : public Interrupt_handler {
	void	interrupt();
	int*	localq;		// data buffer beginning
	int*	localq_end;	// data buffer end
	int*	localq_h;	// queue head
	int*	localq_t;	// queue tail
public:
	int	getX(int&);	// the next item, if any
		Sigint_handler(unsigned local_q_size =QSIZE);
		~Sigint_handler() { delete [/*localq_end - localq*/] localq; }
};

Sigint_handler::Sigint_handler(unsigned local_q_size)
: Interrupt_handler(SIGINT)
{
	localq_t = localq_h = localq = new int[local_q_size];
	localq_end = &localq[local_q_size];
}

int	Global_interrupt_data = 0;

int
get_data()
{
	return Global_interrupt_data++;
}

void
Sigint_handler::interrupt()
{
	register int* p = localq_t;
	*p = get_data();
	if (++p == localq_end) p = localq;
	if (p != localq_h)
		localq_t = p;	// no overflow
	else printf("Sigint_handler::interrupt():  overflow\n");
}

int
Sigint_handler::getX(int& ans)
{
	register int* p = localq_h;
	if (p == localq_t)
		return 0;
	ans = *p;
	if (++p == localq_end) p = localq;
	localq_h = p;
	return 1;
}

class Sigint_printer : public task {
	Sigint_handler*	handler;
public:
		Sigint_printer(char*);
};

Sigint_printer::Sigint_printer(char* n)
: task(n)
{
	handler = new Sigint_handler;
	for(;;) {
		wait(handler);
		int	i;
		printf("%s:\n", n);
		while (handler->getX(i))
			printf("	got:  %d\n", i);
	}
}

const int MAX_SIGS = 5;

class Sig_sender : public task {
	int	nsigs;
public:
		Sig_sender(char*, int);
};

Sig_sender::Sig_sender(char* n, int i)
: task(n)
{
	nsigs = 0;
	while (nsigs < MAX_SIGS) {
		printf("Sig_sender %s:  about to send signal %d.\n", n, i);
		kill(getpid(), i);
		nsigs++;
	}
	printf("Sig_sender %s:  all done.\n", n);
	resultis(0);
}

main()
{
	Sigint_printer* printer_task =
		new Sigint_printer("task Sigint_printer");
	printf("main:  Sigint_printer ready to receive SIGINTS.\n");
	printf("       Sigint_sender will send %d, hit DEL to send more.\n", MAX_SIGS);
	printf("       Use kill -9 %d to kill.\n", getpid());
	new Sig_sender("Sigint_sender", SIGINT);
	printf("main:  all done.\n");
	((object*)0)->this_task()->resultis(0);
}
