#ifndef ASSERTH
#define ASSERTH

/*ident	"@(#)cfront:incl/assert.h	1.3" */
#ifdef NDEBUG
#define assert(EX)
#else
extern void _assert(char*, char*, int);
#define assert(EX) if (EX) ; else _assert("EX", __FILE__, __LINE__)
#endif

#endif
