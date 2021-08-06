object oo = HEX_ADDRESS
object oo = HEX_ADDRESS
Server::Server()
dummy_task::dummy_task(d1p) created
dummy_task2::dummy_task2(d2p) created
main:  task_chain so far:
task
task d2p (RUNNING) 	this = HEX 

task
task d1p (RUNNING) 	this = HEX 

task
task fred (TERMINATED) 	this = HEX 

task
task main (is thistask, RUNNING) 	this = HEX 

task
task Interrupt_alerter (IDLE) 	this = HEX 

main:  who (caused return from waitlist) = 1
main:  who (caused return from waitvec) = 1
dummy_task2:  cancelling myself
time = 0, n = 10, actual_delay = 10
time_left = 20
time out occurred:  clock = 25
About to cancel d1p
fred already terminated with result = 0
About to cancel main
About to cancel Interrupt_alerter
