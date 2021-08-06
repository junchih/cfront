/*ident	"@(#)cls4:incl-master/proto-headers/math.h	1.1" */
#usedby all
/***********************************************************************

	Copyright (c) 1984 AT&T, Inc. All rights Reserved
	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T, INC.

        The copyright notice above does not evidence any
        actual or intended publication of such source code.

**************************************************************************/

#ifndef ___MATH_H
#define ___MATH_H

#os bsd3
#hide infnan
#endos
#os svr2 svr3 sgi
#hide arc
#hide line
#hide space
#endos
#os alliant
#hide isinfinity
#hide isnanf
#endos
#os sunos4 sunos4.1 alliant
#hide isnan
#hide iszero
#endos
#os sunos4 sunos4.1
#hide ilogb
#hide irint
#hide signbit
#hide isinf
#hide isnan
#hide isnormal
#hide issubnormal
#hide nextafter
#hide remainder
#hide significand
#hide scalbn
#hide min_subnormal
#hide max_subnormal
#hide min_normal
#hide max_normal
#hide infinity
#hide quiet_nan
#hide signaling_nan
#hide single
#endos
#os sunos4.1
#hide acospi
#hide aint
#hide anint
#hide annuity
#hide asinpi
#hide atan2pi
#hide atanpi
#hide compound
#hide cospi
#hide exp10
#hide exp2
#hide log2
#hide nint
#hide sincos
#hide sincospi
#hide sinpi
#hide tanpi
#endos
#hide asinh
#hide acosh
#hide atanh
#hide atof
#hide exp
#hide expm1
#hide log
#hide log10
#hide log1p
#hide pow
#hide hypot
#hide cabs
#hide cbrt
#hide sqrt
#hide lgamma
#hide gamma
#hide matherr
#hide fabs
#hide floor
#hide ceil
#hide rint
#hide copysign
#hide drem
#hide logb
#hide scalb
#hide finite
#hide sinh
#hide cosh
#hide tanh
#hide sin
#hide cos
#hide tan
#hide asin
#hide acos
#hide atan
#hide atan2
#hide frexp
#hide ldexp
#hide modf
#hide strtod
#hide erf
#hide erfc
#hide j0
#hide j1
#hide jn
#hide y0
#hide y1
#hide yn
#os bsd2 sunos3 sunos4 sunos4.1 alliant svr2 svr3 sgi hpux2.0 hpux hpux8.0 uts svr4 sgi-svr4 solaris
#hide fmod
#endos
#os svr4 sgi-svr4 solaris
#hide acosf
#hide asinf
#hide atanf
#hide atan2f
#hide cosf
#hide sinf
#hide tanf
#hide coshf
#hide sinhf
#hide tanhf
#hide expf
#hide logf
#hide log10f
#hide powf
#hide sqrtf
#hide ceilf
#hide fabsf
#hide floorf
#hide fmodf
#hide modff
#hide unordered
#hide nextafter
#hide remainder
#hide isnan
#endos
#os sgi-svr4 
#hide drand48
#hide erand48
#hide jrand48
#hide lrand48
#hide mrand48
#hide nrand48
#hide srand48
#hide rand
#hide srand
#hide abs
#endos
#os hpux8.0
#hide abs
#endos

#expand math.h

#os alliant
#include <values.h>
#define M_PI_4	M_PI/4
#define M_PI_2	M_PI/2
#endos

extern "C" {
	double acos(double);
	double asin(double);
	double atan(double);
	double atan2(double, double);
	double atof(const char*);
	double ceil(double);
	double cos(double);
	double cosh(double);
	double erf(double);
	double erfc(double);
	double exp(double);
	double fabs(double);
	double floor(double);
	double frexp(double, int*);
	double gamma(double);
	double hypot(double, double);
	double j0(double);
	double j1(double);
	double jn(int, double);
	double ldexp(double, int);
	double log(double);
	double log10(double);
	double modf(double, double*);
	double pow(double, double);
	double sqrt(double);
	double sin(double);
	double sinh(double);
	double tan(double);
	double tanh(double);
	double y0(double);
	double y1(double);
	double yn(int, double);
#os svr4 sgi-svr4 solaris
	double asinh(double);
	double acosh(double);
	double atanh(double);
	double logb(double);
	double scalb(double, int);
	double nextafter(double,double);
	double remainder(double,double);
	double cbrt(double);
	double lgamma(double);
	double rint(double);
	double copysign(double, double);
	double lgamma(double);
	int finite(double);
	int matherr(struct exception*);
        int unordered(double, double);
	int isnan(double);
        float acosf(float);
        float asinf(float);
        float atanf(float);
        float atan2f(float, float);
        float cosf(float);
        float sinf(float);
        float tanf(float);
        float coshf(float);
        float sinhf(float);
        float tanhf(float);
        float expf(float);
        float logf(float);
        float log10f(float);
        float powf(float, float);
        float sqrtf(float);
        float ceilf(float);
        float fabsf(float);
        float floorf(float);
        float fmodf(float, float);
        float modff(float, float *);
#endos
#os bsd2 sunos3 sunos4 sunos4.1 alliant svr2 svr3 sgi hpux2.0 hpux hpux8.0 uts svr4 sgi-svr4 solaris
	double fmod(double, double);
#endos
#os sunos3 sunos4 sunos4.1 svr2 svr3 sgi hpux2.0 hpux hpux8.0 uts
	int matherr(struct exception*);
#endos
#os alliant sunos4 sunos4.1
	int isnan(double);
	int iszero(double);
#endos
#os alliant
	int isinfinity(double);
	int isnanf(float);
#endos
#os svr2 svr3 sgi
	arc(int, int, int, int, int, int);
	line(int, int, int, int);
	space(int, int, int, int);
#endos
#os bsd3 hpux2.0 hpux hpux8.0 sunos3 sunos4 sunos4.1
	double asinh(double);
	double acosh(double);
	double atanh(double);
#endos
#os sunos4 sunos4.1
	int ilogb(double), irint(double), signbit(double);
	int isinf(double), isnormal(double);
	int issubnormal(double);
	double nextafter(double,double), remainder(double,double);
	double significand(), scalbn(double,int);
	double min_subnormal(), max_subnormal();
	double min_normal(), max_normal();
	double infinity(), quiet_nan(long), signaling_nan(long);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant
	struct ______complex { double x, y;};
	double cabs(______complex);
#endos
#os bsd3 sunos3 sunos4 sunos4.1 
	double expm1(double);
	double log1p(double);
	double cbrt(double);
	double lgamma(double);
	double rint(double);
	double copysign(double, double);
	double drem(double, double);
	double logb(double);
	double scalb(double, int);
	int finite(double);
#endos
#os bsd3
	double infnan(int);
#endos
#os sunos3 sunos4 sunos4.1 
	double strtod(const char*, char**);
#endos
#os sunos4.1
	double acospi(double);
	double aint(double);
	double anint(double);
	double annuity(double);
	double asinpi(double);
	double atan2pi(double, double);
	double atanpi(double);
	double compound(double, double);
	double cospi(double);
	double exp10(double);
	double exp2(double);
	double log2(double);
	int nint(double);
	void sincos(double, double *, double *);
	void sincospi(double, double *, double *);
	double sinpi(double);
	double tanpi(double);
#endos
#os sgi-svr4
	int rand(void);
	void srand(unsigned int);

	double drand48(void);
	double erand48(unsigned short *);
	long jrand48(unsigned short *);
	long lrand48(void);
	long mrand48(void);
	long nrand48(unsigned short *);
	void srand48(long);
	int abs(int);
#endos
}

#os bsd2 sunos3 sunos4 sunos4.1 alliant svr2 svr3 sgi hpux2.0 hpux uts svr4 sgi-svr4 solaris pyramid
inline int sqr(int x) {return(x*x);}
inline double sqr(double x) {return(x*x);}
#endos
#os bsd2 sunos3 sunos4 sunos4.1 alliant svr2 svr3 sgi hpux2.0 hpux uts pyramid hpux8.0

inline int abs(int d) { return (d>0)?d:-d; }
inline double abs(double d) { return fabs(d); }
#endos

#ifndef M_PI
#define M_PI	3.14159265358979323846
#endif
#ifndef PI
#define PI M_PI
#endif

#os svr3
#if pyr
/*
 *  in the Pyramid /usr/include/math.h header file, these
 *  are defined in hex with the "0d" format, which cfront
 *  doesn't understand.
 */
#undef HUGE
#undef MAXFLOAT
#define HUGE		1.79769313486231470e+308
#define MAXFLOAT	((float)3.40282346638528860e+38)
#endif
#endos

#endif
