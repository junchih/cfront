/* @(#) utime.h 1.3 2/16/87 11:02:42 */
/*ident	"@(#)cfront:incl/utime.h	1.3"*/

#ifndef UTIMEH
#define UTIMEH

/* <sys/types.h> must be included */

#ifndef utimbuf
struct utimbuf {
          time_t actime;
          time_t modtime;
       };
#endif

extern int utime (const char*, utimbuf*);

#endif
