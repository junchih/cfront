/* @(#) memory.h 1.4 2/16/87 11:02:22 */
/*ident	"@(#)cfront:incl/memory.h	1.4"*/

#ifndef MEMORYH
#define MEMORYH

extern char
	*memccpy(char*, const char*, int, int),
	*memchr(const char*, int, int),
	*memcpy(char*, const char*, int),
	*memset(char*, int, int);
extern int memcmp(const char*, const char*, int);

#endif
