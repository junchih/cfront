/*
From sfuucp Tue Apr 25 09:34 EDT 1989
>From attunix!srid Tue Apr 25 09:34 EDT 1989 remote from torch
To: attunix!stacey
Subject: task test co1.8.C
Status: RO

 The test I just mailed to you does nothing very facinating. The task "monitor"
 has a waitlist in its constructor. It attempts to make the task "control" 
 wait for the timer(15) using waitlist(sw,0).
  This function call blocks. (Note that if monitor itself is made to wait for
  the timer, it returns once the timer is ready.).

  -pete

*/
#include <task.h>
#include "systest.h"

#define EVER ;;

struct cmds {
  int head;
  cmds* next;
  cmds(int x = 0){ head = x; next = 0; };
};

class Message : public object {
public:
  int head;
  qtail* reply;
  void report();
  Message(int h){ head = h; };
};

class Monitor : public task {
public:
  Monitor(qtail*, cmds*, timer*, task*);
};

Monitor::Monitor(qtail* input, cmds* cmdlist, timer* sw, task*tp){
  cmds* cmdptr = cmdlist;
  for (EVER)
    {	
      sw->reset(15);
      if (tp->rdstate() != IDLE)
	tp->waitlist(sw,0);
      else printf("Error: tp->rdstate() = IDLE unexpected\n");
      printf("wait : returned \n");
      if (cmdptr) {
	input->put(new Message(cmdptr->head));
	cmdptr = cmdptr->next;
      }
      delay(20);
    }	       
};

class Control : public task {
public:
  int head, error, input;
  Control(qhead*, cmds*&);
};

Control::Control(qhead* err,cmds*& cmdlist){
  Message* cntl;
  cmds* cmdptr = cmdlist;
  for (EVER)
    {
      cntl = (Message*) err->get();
      if (cntl)  
	{	
	  cmdptr->next = new cmds(cntl->head);
	  cmdptr = cmdptr->next;
	}
      delay(15);
    }
};

main(){
  cmds *cmd_input, *cmd_output;
  cmd_input = new cmds(30);
  cmd_input->next = new cmds(60);
  cmd_output = new cmds(0);
  qtail* in_queue = new qtail(ZMODE);
  Control* head_control = new Control(in_queue->head(), cmd_output);
  printf("control started\n");
  thistask->delay(10);
  timer* tm = new timer(15);
  Monitor* head_monitor = new Monitor(in_queue,cmd_input, tm , 
				      head_control);
  printf("Monitor started\n");
  thistask->delay(100);
  head_monitor->cancel(0);
  head_control->cancel(0);
  cmd_output = cmd_output->next;
  while (cmd_input)
    {
      if (! cmd_output) {
	printf("%d\n",1);
	thistask->resultis(1);
      }
      if (cmd_input->head != cmd_output->head)
	{
	  printf("%d\n",2);
	  thistask->resultis(2);
	}
      cmd_input = cmd_input->next;
      cmd_output = cmd_output->next;
    }
  printf("%d\n",0);
  thistask->resultis(0);
}
