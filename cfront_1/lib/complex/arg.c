/*ident	"@(#)cfront:lib/complex/arg.c	1.4" */
#include "complex.h"

double
arg(complex z)
{
	return atan2(z.im,z.re);
}
