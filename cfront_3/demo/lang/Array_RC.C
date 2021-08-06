/*ident	"@(#)cls4:demo/lang/Array_RC.C	1.1" */
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
#include "Array_RC.h"
#include "Array.C"

template <class Type>
Array_RC<Type>::Array_RC(int sz) : Array<Type>(sz) {}

template <class Type>
Array_RC<Type>::Array_RC(const Array_RC<Type>& r) : Array<Type>(r) {}

template <class Type>
Array_RC<Type>::Array_RC(Type *ar,int sz) : Array<Type>(ar,sz) {}

template <class Type>
Type &Array_RC<Type>::operator[](int ix) {
        assert(ix >= 0 && ix < size);
        return ia[ix]; }
