/*ident	"@(#) @(#)std_string.h	1.1.1.2" */
/******************************************************************************
*
* C++ Standard Library
*
* Copyright (c) 1996  Lucent Technologies.  All Rights Reserved.
*
* THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF Lucent Technologies.
* The copyright notice above does not evidence any actual or
* intended publication of such source code.
*
******************************************************************************/

#ifndef STDSTRINGHEDG
#define STDSTRINGHEDG

#include "compiler_type.h"

#if defined(COMPILER_IS_EDG_LUCENT)

/* basic_string.h is too complicated for template instantiation */
//#include "basic_string.h"
#include "str_imp.h"
#include "wstr_imp.h"
#if defined(EXCEPTION_LUCENT)
#include <stringexcept.h>
#endif
#ifdef __EDG_IMPLICIT_USING_STD
using namespace std;
#endif

#else

#include "std_bool.h"
#include "str_imp.h"
#include "wstr_imp.h"

#endif

#endif
