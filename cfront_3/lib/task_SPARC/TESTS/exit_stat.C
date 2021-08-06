#include <task.h>

const int STATUS = 1;

struct simple_task : task {
        simple_task(char*);
};

simple_task::simple_task(char* n) :task(n)
{
	int s = get_exit_status();
	if (s == 0) {
		printf("exit_status = %d\n", s);
		set_exit_status(STATUS); 
		printf("exit_status = %d\n", get_exit_status());
	}
	resultis(0);	//return control to main
}

main()
{
	printf("exit_status = %d\n", sched::get_exit_status());
        simple_task *st = new simple_task("st");
	thistask->delay(10);	// ensure st gets control
	if( sched::get_exit_status() != STATUS) {
		// Not OK, program will return -1
		sched::set_exit_status(-1);
	} else {
		//OK, program should return 0
		printf("exit_status = %d\n", thistask->get_exit_status());
		thistask->set_exit_status(0);
	}
	thistask->resultis(0);
}

