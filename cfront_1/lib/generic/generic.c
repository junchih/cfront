/*ident	"@(#)cfront:lib/generic/generic.c	1.3" */
#include <stdio.h>

extern genericerror(int n, char* s)
{
	fprintf(stderr,"%s\n",s?s:"error in generic library function",n);
	abort(111);
	return 0;
};
