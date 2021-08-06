#include <task.h>

/*  Test of random number generating classes in libtask
 */

const int MAXI = 10000;

main()
{
	int r;
	urand ur(5,7);
	histogram H(3,5,7);
	for (int i = 1; i <= MAXI; i++) {
		r = ur.draw();
		H.add(r);
		//if (i % 10)	printf("r = %d\t", r);
		//else		printf("r = %d\n", r);
	}
	printf("Histogram H:\n");
	H.print();
	thistask->resultis(0);
}
