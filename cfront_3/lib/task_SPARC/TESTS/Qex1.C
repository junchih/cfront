#include <task.h>
#include <stdlib.h>

/*
 * Qex1.C
 * Example based on "A Server Example" section in Stroustrup/Shopiro
 * coroutine memo, Release Notes pp 13-6 - 13-7.
 * Uses message queues to communicate with Server task.
 */

typedef enum { PLUS, MINUS, VALUE, ERROR } op_type;

class Message : public object
{
public:
	int	r_operation;
	int	r_arg1;
	int	r_arg2;
	qtail*	r_reply;
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

class Server : public task
{
public:
	Server(qhead *);
};

Server::Server(qhead* in)
{
	for(;;) {
		printf("Server::Server:\n");
		Message*	req = (Message *) in->get();
		printf("Server::Server:  got Message\n");
		qtail*		reply = req->r_reply;
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
	qtail*	rq = new qtail;		// Server request queue
	Server*	ser = new Server(rq->head());
	
	qhead*	rply = new qhead;	// Server reply queue
	qtail*	rply_to = rply->tail();
	Message*	mess = new Message;

	mess->r_operation = PLUS;
	mess->r_arg1 = 1;
	mess->r_arg2 = 2;
	mess->r_reply = rply_to;

	printf("main:  about to put message:\n");
//SAK:  defaults not getting picked up for some reason
//SAK:	mess->print();
	mess->print(0,0);
	rq->put(mess);
	mess = (Message *) rply->get();
	printf("main:  got message\n");
//SAK:  defaults not getting picked up for some reason
//SAK:	mess->print();
	mess->print(0,0);
	if (mess->r_operation == ERROR) {
		printf("main:  r_operation == ERROR\n");
		exit(1);
	}
	thistask->resultis(0);
}
