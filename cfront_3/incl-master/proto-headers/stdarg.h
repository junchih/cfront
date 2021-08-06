/*ident	"@(#)cls4:incl-master/proto-headers/stdarg.h	1.1" */
#usedby all

/*******************************************************************************
 
C++ source for the C++ Language System, Release 3.0.  This product
is a new release of the original cfront developed in the computer
science research center of AT&T Bell Laboratories.

Copyright (c) 1991 AT&T and UNIX System Laboratories, Inc.
Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.

THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
Laboratories, Inc.  The copyright notice above does not evidence
any actual or intended publication of such source code.

*******************************************************************************/
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

#ifdef pyr
typedef int     va_buf[3];
typedef va_buf  *va_list;

extern "C"
{
	extern void     _vastart(va_list, char*);
	extern char     *_vaarg(va_list, int);
}

#define         va_start(ap, parmN)     {\
        va_buf  _va;\
        _vastart(ap = (va_list)_va, (char *)&parmN + sizeof parmN)
#define         va_end(ap)      }
#define         va_arg(ap, mode)        *((mode *)_vaarg(ap, sizeof (mode)))
#else
#ifdef hp9000s800
typedef double *va_list;
#    define __WORD_MASK 0xFFFFFFFC
#    define __DW_MASK   0xFFFFFFF8
#else
typedef char *va_list;
#endif
#define va_end(ap)
#ifdef u370
#define va_start(ap, parmN) ap =\
	(char *) ((int)&parmN + 2*sizeof(parmN) - 1 & -sizeof(parmN))
#define va_arg(ap, mode) ((mode *)(ap = \
	(char *) ((int)ap + 2*sizeof(mode) - 1 & -sizeof(mode))))[-1]
#else
#ifdef hp9000s800
/* We are trying to mimick what HP's C++ compiler does for va_start.
   This will only work if cfront is also mimicking what HP does. */
extern "C" {
         void __builtin_va_start(va_list, ...);
}
extern long va_alist; /* This is needed to keep cfront happy */
#    define va_start(__list,__parmN) (__list=0, __builtin_va_start(__list,&va_alist))
#    define va_arg(__list,__mode)               \
        (sizeof(__mode) > 8 ?                   \
          ((__list = (va_list) ((char *)__list - sizeof (int))),\
          (*((__mode *) (*((int *) (__list)))))) :      \
          ((__list =                                    \
              (va_list) ((long)((char *)__list - sizeof (__mode))\
              & (sizeof(__mode) > 4 ? __DW_MASK : __WORD_MASK))),\
           (*((__mode *) ((char *)__list +              \
                ((8 - sizeof(__mode)) % 4))))))
#else
#ifdef hp9000s300
#define va_start(ap, parmN) (ap = (char *)&parmN + sizeof(parmN),(void)va_arg(ap,int))
#define va_arg(ap, mode) ((mode *)(ap = (char *)((int)(ap-sizeof(mode)) & ~(sizeof(mode)-1))))[0]
#else
#ifdef sparc
/* The following declaration is to fool cfront -- __builtin_va_alist 
   isn't a normal variable, it is a magic word to the Sun 4 C compiler.
 */
extern int __builtin_va_alist;
/* The reference to __builtin_va_alist is needed for Sun 4.  It prevents
   the optimizer from taking out the code that puts the function arguments
   on the stack.
 */
#define va_start(ap, parmN) { int *jnk = &__builtin_va_alist; (void)&jnk; } ap = (char *)( &parmN+1 )
#else
#define va_start(ap, parmN) ap = (char *)( &parmN+1 )
#endif
#os sunos4.1
#ifdef sparc
extern "C" void *__builtin_va_arg_incr(...);
#define va_arg(ap, mode) ((mode *)__builtin_va_arg_incr((mode *)ap))[0]
#else
#endos
#define va_arg(ap, mode) ((mode *)(ap += sizeof(mode)))[-1]
#endif
#os sunos4.1
#endif
#endos
#endif
#endif
#endif

#if !pyr || !BSD
#include	<stdio.h>
extern "C" {
extern int vprintf(const char*, va_list),
	vfprintf(FILE*, const char*, va_list),
	vsprintf(char*, const char*, va_list);
}
#endif
#endif

#endif
