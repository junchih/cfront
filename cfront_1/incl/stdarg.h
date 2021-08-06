/* @(#) stdarg.h 1.4 2/16/87 11:02:31 */
/*ident	"@(#)cfront:incl/stdarg.h	1.4"*/
/* stdarg.h */
/* ADAPTED FROM: */
/*	@(#)varargs.h	1.2	*/

#ifndef STDARGH
#define STDARGH

/*
	USAGE:
		f( arg-declarations ... ) {
			va_list ap;
			va_start(ap, parmN);	// parmN == last named arg
			// ...
			type arg = va_arg(ap, type);
			// ...
			va_end(ap);
		}
*/

#ifndef va_start

#if pyr

#define _VALEN  3
typedef int va_buf[_VALEN];
typedef va_buf *va_list;
extern void _vastart(va_list, void *);
extern va_list _vaarg(va_list, int);
#define va_start(list, parmN) {\
        va_buf _va;\
        _vastart(list = (va_list)_va, &parmN);\
	}
#define va_arg(list, mode)  *((mode *)_vaarg(list, sizeof(mode)))
#define va_end(list)

#else ~pyr
typedef char *va_list;
#define va_end(ap)
#ifdef u370
#define va_start(ap, parmN) ap =\
	(char *) ((int)&parmN + 2*sizeof(parmN) - 1 & -sizeof(parmN))
#define va_arg(ap, mode) ((mode *)(ap = \
	(char *) ((int)ap + 2*sizeof(mode) - 1 & -sizeof(mode))))[-1]
#else
#define va_start(ap, parmN) ap = (char *)( &parmN+1 )
#define va_arg(ap, mode) ((mode *)(ap += sizeof(mode)))[-1]
#endif
#endif

extern int vprintf(char*, va_list),
	vfprintf(FILE*, char*, va_list),
	vsprintf(char*, char*, va_list),
	setvbuf(FILE*, char*, int, int);
#endif

#endif
