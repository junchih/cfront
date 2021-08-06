#include <task.h>

/*
 * Spaces.C
 * Simple example from "Tasks" section of Stroustrup/Shopiro coroutine memo,
 * Release Notes pp 13-4.
 * Shows task basics:  creation, termination, "returning" values, blocking.
 */


class Spaces : public task
{
public:
	Spaces(char*);
};

Spaces::Spaces(register char* s)
{
	register int	i = 0;
	register char	c;
	while (c = *s++)
		if (c == ' ') i++;
	resultis(i);
}

main()
{
	Spaces ss("a line with four spaces");
	int count = ss.result();
	printf("count = %d\n", count);
	thistask->resultis(0);
}
