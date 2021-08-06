/*ident	"@(#)cls4:demo/lang/Array_RC_S.C	1.1" */
/*#########################################################################
#                       Copyright (c) 1991 AT&T
#                         All Rights Reserved   
#
#                THIS IS PROPRIETARY SOURCE CODE OF AT&T
#       
#                     This code has been published in
#                         C++ Primer, 2nd Edition 
#			    by Stanley Lippman
#                    Addison_Wesley Publishing Company
#
#########################################################################*/
#include "Array_RC_S.h"

template <class Type>
Array_RC_S<Type>:: 
Array_RC_S(const Array_RC_S<Type>& rca)
	: Array<Type>( rca )
	{ sort(0,size-1); clear_bit(); }

template <class Type>
Array_RC_S<Type>:: 
Array_RC_S(Type* arr, int sz)
	: Array<Type>( arr, sz )
	{ sort(0,size-1); clear_bit(); }
