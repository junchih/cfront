#include <task.h>
#include <stdlib.h>

/*
 * Qex2.C
 * Example based on Server example, adding ctor and member functions
 * to class Message.  From "Encapsulation" section of Stroustrup/Shopiro
 * coroutine memo, Release Notes pp 13-15 - 13-16.
 * Builds on Qex1.C:  adds constructor and member functions to Message class,
 * derives a special queue type for Message objects.
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
	Message*	get() { return (Message *) qhead::get(); }
};

class Mqtail : public qtail
{
public:
	int	put(Message* m) { return qtail::put(m); }
};

class Server : public task
{
public:
		Server(Mqhead *);
};

Server::Server(Mqhead* in)
{
	for(;;) {
		printf("Server::Server:\n");
		Message*	req = in->get();
		printf("Server::Server:  got Message\n");
//SAK:  defaults not getting picked up for some reason
//SAK:		req->print();
		req->print(0,0);
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
		reply->put(req);
	}
}

main()
{
	Mqtail*	rq = new Mqtail;
	Server*	ser = new Server((Mqhead*) rq->head());
	
	Mqhead*	rply = new Mqhead;
	Mqtail*	rply_to = (Mqtail*) rply->tail();
	Message*	mess;

	printf("main:  about to put message:\n");
	rq->put(new Message(PLUS, 1, 2, rply_to));
	mess =  (Message *) rply->get();
	printf("main:  got message:\n");
//SAK:  defaults not getting picked up for some reason
//SAK:	mess->print();
	mess->print(0,0);
	if (mess->r_operation == ERROR) {
		printf("main:  r_operation == ERROR\n");
		exit(1);
	}
	thistask->resultis(0);
}
