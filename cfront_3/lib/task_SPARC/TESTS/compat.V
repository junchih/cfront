main
new pc(a)
main()'s loop
new pc(b)
main()'s loop
new pc(first pc)
main: here we go
task HEX (first pc), state = 1, state_string = IDLE
task HEX (b), state = 1, state_string = IDLE
task HEX (a), state = 1, state_string = IDLE
task HEX (main), state = 2, state_string = RUNNING
task HEX (Interrupt_alerter), state = 1, state_string = IDLE
main: exit
task b
task a
task first pc
task b
task a
task first pc
task b
task a
task first pc
task b
task a
task first pc
task b
task b: done.
call_frames(25) returned HEX
task
task b (is thistask, RUNNING) 	this = HEX 
	mode=DEDICATED t_alert HEX t_next HEX s_time=0
	stack: 	sizes:	max=750, current=44, hwm=305
		addresses:	t_basep HEX  t_framep HEX
				max HEX  current HEX  hwm HEX
	sched:  this HEX
	object:  this HEX
	No tasks remembered

run chain is:
task
task a (RUNNING) 	this = HEX 

end of run chain.

Chain of all tasks:
Next task on chain of all tasks is:
task
task first pc (IDLE) 	this = HEX 
	mode=DEDICATED t_alert HEX t_next HEX s_time=0
	stack: 	sizes:	max=750, current=99, hwm=152
		addresses:	t_basep HEX  t_framep HEX
				max HEX  current HEX  hwm HEX
	sched:  this HEX
	object:  this HEX
	No tasks remembered

Next task on chain of all tasks is:
task
task b (is thistask, RUNNING) 	this = HEX 
	mode=DEDICATED t_alert HEX t_next HEX s_time=0
	stack: 	sizes:	max=750, current=59, hwm=305
		addresses:	t_basep HEX  t_framep HEX
				max HEX  current HEX  hwm HEX
	sched:  this HEX
	object:  this HEX
	No tasks remembered

Next task on chain of all tasks is:
task
task a (RUNNING) 	this = HEX 
	mode=DEDICATED t_alert HEX t_next HEX s_time=0
	stack: 	sizes:	max=750, current=99, hwm=157
		addresses:	t_basep HEX  t_framep HEX
				max HEX  current HEX  hwm HEX
	sched:  this HEX
	object:  this HEX
	No tasks remembered

Next task on chain of all tasks is:
task
task main (TERMINATED) 	this = HEX 
	mode=DEDICATED t_alert HEX t_next HEX result=0
	stack: deleted.  hwm size=0, hwm address HEX
	sched:  this HEX
	object:  this HEX
	No tasks remembered

Next task on chain of all tasks is:
task
task Interrupt_alerter (IDLE) 	this = HEX 
	mode=DEDICATED t_alert=0 t_next=0 s_time=0
	stack: 	sizes:	max=750, current=71, hwm=750
		addresses:	t_basep HEX  t_framep HEX
				max HEX  current HEX  hwm HEX
	sched:  this HEX
	object:  this HEX
	No tasks remembered

task a
task a: done.
call_frames(25) returned HEX
task
task a (is thistask, RUNNING) 	this = HEX 
	mode=DEDICATED t_alert HEX t_next HEX s_time=0
	stack: 	sizes:	max=750, current=44, hwm=305
		addresses:	t_basep HEX  t_framep HEX
				max HEX  current HEX  hwm HEX
	sched:  this HEX
	object:  this HEX
	No tasks remembered

run chain is:
task
task first pc (RUNNING) 	this = HEX 

end of run chain.

Chain of all tasks:
Next task on chain of all tasks is:
task
task first pc (RUNNING) 	this = HEX 
	mode=DEDICATED t_alert HEX t_next HEX s_time=0
	stack: 	sizes:	max=750, current=99, hwm=152
		addresses:	t_basep HEX  t_framep HEX
				max HEX  current HEX  hwm HEX
	sched:  this HEX
	object:  this HEX
	No tasks remembered

Next task on chain of all tasks is:
task
task b (TERMINATED) 	this = HEX 
	mode=DEDICATED t_alert HEX t_next HEX result=0
	stack: deleted.  hwm size=305, hwm address HEX
	sched:  this HEX
	object:  this HEX
	No tasks remembered

Next task on chain of all tasks is:
task
task a (is thistask, RUNNING) 	this = HEX 
	mode=DEDICATED t_alert HEX t_next HEX s_time=0
	stack: 	sizes:	max=750, current=59, hwm=305
		addresses:	t_basep HEX  t_framep HEX
				max HEX  current HEX  hwm HEX
	sched:  this HEX
	object:  this HEX
	No tasks remembered

Next task on chain of all tasks is:
task
task main (TERMINATED) 	this = HEX 
	mode=DEDICATED t_alert HEX t_next HEX result=0
	stack: deleted.  hwm size=0, hwm address HEX
	sched:  this HEX
	object:  this HEX
	No tasks remembered

Next task on chain of all tasks is:
task
task Interrupt_alerter (IDLE) 	this = HEX 
	mode=DEDICATED t_alert=0 t_next=0 s_time=0
	stack: 	sizes:	max=750, current=71, hwm=750
		addresses:	t_basep HEX  t_framep HEX
				max HEX  current HEX  hwm HEX
	sched:  this HEX
	object:  this HEX
	No tasks remembered

task first pc
task first pc: done.
call_frames(25) returned HEX
task
task first pc (is thistask, RUNNING) 	this = HEX 
	mode=DEDICATED t_alert HEX t_next HEX s_time=0
	stack: 	sizes:	max=750, current=44, hwm=305
		addresses:	t_basep HEX  t_framep HEX
				max HEX  current HEX  hwm HEX
	sched:  this HEX
	object:  this HEX
	No tasks remembered

run chain is empty
Next task on chain of all tasks is:
task
task b (TERMINATED) 	this = HEX 
	mode=DEDICATED t_alert HEX t_next HEX result=0
	stack: deleted.  hwm size=305, hwm address HEX
	sched:  this HEX
	object:  this HEX
	No tasks remembered

Next task on chain of all tasks is:
task
task a (TERMINATED) 	this = HEX 
	mode=DEDICATED t_alert HEX t_next HEX result=0
	stack: deleted.  hwm size=305, hwm address HEX
	sched:  this HEX
	object:  this HEX
	No tasks remembered

Next task on chain of all tasks is:
task
task main (TERMINATED) 	this = HEX 
	mode=DEDICATED t_alert HEX t_next HEX result=0
	stack: deleted.  hwm size=0, hwm address HEX
	sched:  this HEX
	object:  this HEX
	No tasks remembered

Next task on chain of all tasks is:
task
task Interrupt_alerter (IDLE) 	this = HEX 
	mode=DEDICATED t_alert=0 t_next=0 s_time=0
	stack: 	sizes:	max=750, current=71, hwm=750
		addresses:	t_basep HEX  t_framep HEX
				max HEX  current HEX  hwm HEX
	sched:  this HEX
	object:  this HEX
	No tasks remembered

