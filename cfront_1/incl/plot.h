/* @(#) plot.h 1.4 2/16/87 11:02:25 */
/*ident	"@(#)cfront:incl/plot.h	1.4"*/

#ifndef PLOTH
#define PLOTH

extern int arc (int, int, int, int, int, int),
           circle (int, int, int),
           closepl (),
           cont (int, int),
           erase (),
           label (const char*),
           line (int, int, int, int),
           linemod (const char*),
           move (int, int),
           openpl (),
           point (int, int),
           space (int, int, int, int);

#endif
