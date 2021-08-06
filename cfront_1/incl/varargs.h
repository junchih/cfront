/*ident	"@(#)cfront:incl/varargs.h	1.2" */

#ifndef VARARGSH
#define VARARGSH

#if pyr

#define	_VALEN	3
typedef	int va_buf[_VALEN];
typedef va_buf *va_list;
extern void _vastart(va_list, void *);
extern va_list _vaarg(va_list, int);

#define va_dcl
#define va_start(list) {\
	va_buf _va;\
	_vastart(list = (va_list)_va, &va_alist);\
	}
#define va_end(list)
#define va_arg(list, mode)  *((mode *)_vaarg(list, sizeof(mode)))

#else /* ~pyr */
typedef char *va_list;
#define va_dcl int va_alist;
#define va_start(list) list = (char *) &va_alist
#define va_end(list)
#ifdef u370
#define va_arg(list, mode) ((mode *)(list = \
	(char *) ((int)list + 2*sizeof(mode) - 1 & -sizeof(mode))))[-1]
#else
#define va_arg(list, mode) ((mode *)(list += sizeof(mode)))[-1]
#endif
#endif

#include <stdio.h>
extern int vprintf(char*, va_list),
	vfprintf(FILE*, char*, va_list),
	vsprintf(char*, char*, va_list),
	setvbuf(FILE*, char*, int, int);

#endif
