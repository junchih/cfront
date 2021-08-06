main
new pc(a)
ntasks = 2
main()'s loop
new pc(b)
ntasks = 3
main()'s loop
new pc(first pc)
ntasks = 4
main: ntasks = 4
main: task_chain is:
task
task first pc (IDLE) 	this = HEX 

task
task b (IDLE) 	this = HEX 

task
task a (IDLE) 	this = HEX 

task
task main (is thistask, RUNNING) 	this = HEX 

task
task Interrupt_alerter (IDLE) 	this = HEX 

main: here we go
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
task a
task a: done.
task first pc
task first pc: done.
