/*ident	"@(#)cfront:lib/complex/polar.c	1.4" */
#include	"complex.h"

complex
polar(double r, double theta)
{
	return complex(r * cos(theta), r * sin(theta) );
}
