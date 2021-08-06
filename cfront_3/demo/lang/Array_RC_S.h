/*ident	"@(#)cls4:demo/lang/Array_RC_S.h	1.1" */
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
#ifndef ARRAY_RC_S_H
#define ARRAY_RC_S_H

#include "Array_S.C"
#include "Array_RC.C"

template <class Type>
class Array_RC_S : public Array_RC<Type>, 
		   public Array_Sort<Type>
{
public:
    Array_RC_S(int sz = ArraySize)
        : Array<Type>( sz ){ clear_bit(); }

    Array_RC_S(const Array_RC_S& rca);
    Array_RC_S(Type* arr, int sz);

    Type& operator[](int index) { 
        set_bit();
	return Array_RC<Type>::operator[](index); 
    }
};

#endif
