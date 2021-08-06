/*ident	"@(#)cls4:demo/lang/Array_RC.h	1.1" */
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
#ifndef ARRAY_RC_H
#define ARRAY_RC_H

#include "Array.h"

template <class Type>
class Array_RC : public virtual Array<Type> {
public:
    Array_RC(int sz=ArraySize);
    Array_RC(const Array_RC& r);
    Array_RC(Type *ar,int sz);
    Type& operator[](int ix); 
};

#endif
