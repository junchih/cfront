/*ident	"@(#)cls4:incl-master/proto-headers/floatingpoint.h	1.1" */
#usedby solaris

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
#ifndef __FLOATINGPOINT_H
#define __FLOATINGPOINT_H

#hide single_to_decimal
#hide double_to_decimal
#hide extended_to_decimal
#hide quadruple_to_decimal
#hide decimal_to_single
#hide decimal_to_double
#hide decimal_to_extended
#hide decimal_to_quadruple
#hide string_to_decimal
#hide func_to_decimal
#hide seconvert
#hide sfconvert
#hide sgconvert
#hide econvert
#hide fconvert
#hide gconvert
#hide qeconvert
#hide qfconvert
#hide qgconvert
#hide fcvt
#hide ecvt
#hide gcvt
#hide strtod
#hide atof

#expand floatingpoint.h

extern "C" {
	void single_to_decimal (single *, decimal_mode *, decimal_record *,
                               fp_exception_field_type *);
	void double_to_decimal (double *, decimal_mode *, decimal_record *,
                               fp_exception_field_type *);
	void extended_to_decimal (extended *, decimal_mode *,
                               decimal_record *, fp_exception_field_type *);
	void quadruple_to_decimal (quadruple *, decimal_mode *,
                               decimal_record *, fp_exception_field_type *);

	void decimal_to_single (single *, decimal_mode *, decimal_record *,
                               fp_exception_field_type *);
	void decimal_to_double (double *, decimal_mode *, decimal_record *,
                               fp_exception_field_type *);
	void decimal_to_extended (extended *, decimal_mode *,
                               decimal_record *, fp_exception_field_type *);
	void decimal_to_quadruple (quadruple *, decimal_mode *,
                               decimal_record *, fp_exception_field_type *);

	void string_to_decimal (char **, int, int, decimal_record *,
                               enum decimal_string_form *, char **);
	void func_to_decimal (char **, int, int, decimal_record *,
                               enum decimal_string_form *, char **,
                               int (*)(void), int *, int (*)(int));
	char *seconvert (single *, int, int *, int *, char *);
	char *sfconvert (single *, int, int *, int *, char *);
	char *sgconvert (single *, int, int, char *);
	char *econvert (double, int, int *, int *, char *);
	char *fconvert (double, int, int *, int *, char *);
	char *gconvert (double, int, int, char *);
	char *qeconvert (quadruple *, int, int *, int *, char *);
	char *qfconvert (quadruple *, int, int *, int *, char *);
	char *qgconvert (quadruple *, int, int, char *);
	char *fcvt(double, int, int*, int*);
        char *ecvt(double, int, int*, int*);
        char *gcvt(double, int, char*);
	double atof(const char*);
	double strtod(const char*, char**);
}
#endif
