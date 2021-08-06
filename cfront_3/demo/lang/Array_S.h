/*ident	"@(#)cls4:demo/lang/Array_S.h	1.1" */
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
#ifndef ARRAY_S_H_
#define ARRAY_S_H_
#include "Array.h"

template <class Type>
class Array_Sort : public virtual Array<Type> {
protected:
    void set_bit() { dirty_bit = 1; }
    void clear_bit() { dirty_bit = 0; }
    void check_bit() { 
      if (dirty_bit) { sort(0,size-1); clear_bit(); }
    }
public:
    Array_Sort(const Array_Sort&);
    Array_Sort(int sz=ArraySize);

    Array_Sort(Type* arr, int sz) 
        : Array<Type>(arr, sz)
	{ sort(0,size-1); clear_bit(); }

    Type& operator[](int ix) 
	{ set_bit(); return ia[ix]; }

    void print(ostream& os = cout) 
	{ check_bit(); Array<Type>::print(os); }

    Type min() { check_bit(); return ia[0]; }
    Type max() { check_bit(); return ia[size-1]; }

    int is_dirty() const { return dirty_bit; }
    int find(Type);
    void grow(); 

protected:
    char dirty_bit;
};

#endif
