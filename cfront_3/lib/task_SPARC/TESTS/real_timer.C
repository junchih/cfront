#include "real_timer.h"
#include <stdio.h>

#define STATIC

unsigned	alarm(unsigned);
long		time(long*);

// only one instance of this class
class Alarm_handler : public task {
	friend Real_timer;
	Real_timer*	chain;
	Interrupt_handler*	bell;
	void	add_timer(Real_timer*);
	void	remove_timer(Real_timer*);
public:
		Alarm_handler();
};

Alarm_handler	alarm_handler;

Alarm_handler::Alarm_handler()
: task("Alarm_handler"), chain(0)
{
	sleep();
	for(;;) {
		for (long now = time(0); chain && chain->time <= now;
				chain = (Real_timer*)chain->o_next)
			chain->resume();
		if (chain) {
			alarm(chain->time - now);
			wait(bell);
		} else {
			bell->forget(this_task());
			delete bell;
			sleep();
		}
	}
}
	
void
Alarm_handler::add_timer(Real_timer* r)
{
	register Real_timer * p;
	register Real_timer * pp;

	unsigned delay = r->time;
	register long tt = r->time = time(0) + delay;
	/* chain ordered by time */
	if (p = chain) {
		if (tt < p->time) {
			r->o_next = chain;
			chain = r;
			alarm(delay);
		} else {
			while (pp = (Real_timer*)p->o_next) {
				if (r->time < pp->time) {
					r->o_next = pp;
					break;
				} else p = pp;
			}
			p->o_next = r;
		}
	} else {
		chain = r;
		bell = new Interrupt_handler(SIGALRM);
		bell->remember(this);
		alarm(delay);
	}
}
	
void
Real_timer::insert(int d)
{
	switch (state) {
	case TERMINATED:
		task_error(E_RESTERM);
		break;
	case IDLE:
		break;
	case RUNNING:
		task_error(E_RESRUN);
	}

	if (d<=0) task_error(E_NEGTIME);	

	if (o_next) task_error(E_RESOBJ);

	state = RUNNING;
	alarm_handler.add_timer(this);
}

void
Alarm_handler::remove_timer(Real_timer* r)
// remove from chain and make IDLE
{
	register class Real_timer * p;
	register class Real_timer * pp;

	alarm(0);
	if (p = chain)
		if (p == r)
			if (chain = (Real_timer*)r->o_next) {
				int delay = chain->time - time(0);
				if (delay > 0) alarm(delay);
			} else {
				alarm(0);
				bell->forget(this);
				delete bell;
			}
		else
			for (; pp = (Real_timer*)p->o_next; p=pp)
				if (pp == r) {
					p->o_next = pp->o_next;
					break;
				}
	r->state = IDLE;
	r->o_next = 0;
}

void
Real_timer::remove()
// remove from chain and make IDLE
{
	alarm_handler.remove_timer(this);
}

void
Real_timer::reset(int d)
{
	remove();
	insert(d);
}

void
Real_timer::resume()  // time is up
{
fprintf(stderr, "Real_timer::resume()\n");
	state = TERMINATED;
	alert();
}

int
Real_timer::pending()  // do we wait for this timer?
{
	return state != TERMINATED;
}

void
Real_timer::print(int n, int baseClass)
{
	if (!baseClass)
		fprintf(stderr, "Real_timer %ld==now+%ld, state==%s\n", time,
			time - ::time(0),
			state==RUNNING ? "RUNNING" :
			  state==IDLE ? "IDLE" :
			  state==TERMINATED ? "TERMINATED" : "error");

	object::print(n, 1);
}

int
Real_timer::o_type()
{
	return REAL_TIMER;
}

Real_timer::Real_timer(int d)
: time(d), state(IDLE)
{
	insert(d);
}

Real_timer::~Real_timer()
{
	if (state != TERMINATED) task_error(E_TIMERDEL);
}
