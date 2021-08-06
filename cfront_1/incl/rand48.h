/* @(#) rand48.h 1.3 2/16/87 11:02:28 */
/*ident	"@(#)cfront:incl/rand48.h	1.3"*/

#ifndef RAND48H
#define RAND48H

extern double drand48 (),
              erand48 (unsigned short);

extern long lrand48 (),
            nrand48 (unsigned short),
            mrand48 (),
            jrand48 (unsigned short);

extern void lcong48 (unsigned short);
extern void srand48 (long);

extern unsigned short *seed48 (unsigned short);

#endif
