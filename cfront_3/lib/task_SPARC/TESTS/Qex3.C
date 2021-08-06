#include <task.h>
#include <stdlib.h>

/*
 * Qex3.C
 * Example based on Server "plus_and_minus" example
 * from "Encapsulation" section of Stroustrup/Shopiro coroutine memo,
 * Release Notes pp 13-16 - 13-17.
 * Builds on Qex2.C:  adds Server member functions for requesting services.
 */

typedef enum { PLUS, MINUS, VALUE, ERROR } op_type;

class Mqhead;
class Mqtail;

class Message : public object
{
public:
	int	r_operation;
	int	r_arg1;
	int	r_arg2;
	Mqtail*	r_reply;
		Message(int op, int a1, int a2, Mqtail* rp) :
			r_operation(op), r_arg1(a1),
			r_arg2(a2), r_reply(rp) {}
	void	print(int =0, int =0);
};

void
Message::print(int i, int j)
{
	printf("r_operation:\t");
	switch(r_operation) {
	case PLUS :	printf("PLUS\n");
			break;
	case MINUS :	printf("MINUS\n");
			break;
	case ERROR :	printf("ERROR\n");
			break;
	case VALUE :	printf("VALUE\n");
			break;
	default :	printf("INVALID\n");
	}
	printf("r_arg1:\t\t%d\n", r_arg1);
	printf("r_arg2:\t\t%d\n", r_arg2);
	printf("r_reply:\t%x\n", r_reply);
//	printf("r_reply:\tHEX ADDRESS\n");
}

class Mqhead : public qhead
{
public:
	//Mqhead();
	Message*	get() { return (Message *) qhead::get(); }
};

class Mqtail : public qtail
{
public:
	//Mqtail();
	int	put(Message* m) { return qtail::put(m); }
};

class Server : public task
{
	Mqtail*	req_qt;	// Requesters put messages on this qtail
	Mqhead*	req_qh;	// Server reads messages from this qhead
public:
		Server(char *);
	int	plus(int, int, Mqtail *);
	int	minus(int, int, Mqtail *);
};

Server::Server(char *name) : task(name)
{
	req_qt = new Mqtail;
	req_qh = (Mqhead*) req_qt->head();
	for(;;) {
		printf("Server::Server:\n");
		Message*	req = req_qh->get();
		printf("Server::Server:  got Message\n");
//SAK:  defaults not getting picked up for some reason
//SAK:		req->print();
		req->print(0);
		Mqtail*		reply = req->r_reply;
		int		res = VALUE;
		int		val;
		switch (req->r_operation) {
		case PLUS:
			val = req->r_arg1 + req->r_arg2;
			break;
		case MINUS:
			val = req->r_arg1 - req->r_arg2;
			break;
		default:
			res = ERROR;
		}
		req->r_operation = res;
		req->r_arg1 = val;
		printf("Server::Server:  about to put Message\n");
		req->print(0,0);
		reply->put(req);
	}
}

int
Server::plus(int arg1, int arg2, Mqtail *rqt)
{
	Message	*mess;
	int	val;
	req_qt->put(new Message(PLUS, arg1, arg2, rqt));
	mess = ((Mqhead*)rqt->head())->get();
	
	printf("Server::plus:  got message:\n");
//SAK:  defaults not getting picked up for some reason
//SAK:	mess->print();
	mess->print(0,0);
	if (mess->r_operation == ERROR) {
		printf("Server::plus:  r_operation == ERROR\n");
		exit(1);
	}
	val = mess->r_arg1;
	delete mess;
	return val;
}

int
Server::minus(int arg1, int arg2, Mqtail *rqt)
{
	Message	*mess;
	int	val;
	req_qt->put(new Message(MINUS, arg1, arg2, rqt));
	mess = ((Mqhead*)rqt->head())->get();

	printf("Server::minus:  got message:\n");
//SAK:  defaults not getting picked up for some reason
//SAK:	mess->print();
	mess->print(0,0);
	if (mess->r_operation == ERROR) {
		printf("Server::minus:  r_operation == ERROR\n");
		exit(1);
	}
	val = mess->r_arg1;
	delete mess;
	return val;
}

main()
{
	Mqtail*	resp_qt = new Mqtail;
	Server	ss("plus_and_minus");	// Server sets up its own queues
	int	two = ss.plus(1, 1, resp_qt);
	printf("main:  two = %d\n", two);
	int	ten = ss.minus(12, 2, resp_qt);
	printf("main:  ten = %d\n", ten);

	thistask->resultis(0);
}
