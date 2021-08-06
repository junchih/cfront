/*ident	"@(#)cls4:demo/lang/Array.h	1.1" */
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
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream.h>

template <class Type> class Array;
template <class Type> ostream& 
    operator<<(ostream&,Array<Type>&);

enum { ArraySize = 24, not_found = -1 };
template <class Type>
class Array {
public: 
//    enum { ArraySize = 24, not_found = -1 };
    Array(int sz=ArraySize); // { init(0,sz); }
    Array(Type *ar, int sz); // { init(ar,sz); }
    Array(const Array &iA);  // { init(iA.ia,iA.size); }
    virtual ~Array() { delete ia; }

    Array& operator=(const Array&);
    int getSize() { return size; }
    virtual void grow();
    virtual void print(ostream& = cout);

    virtual Type& operator[](int ix) { return ia[ix]; }
    virtual void sort(int,int);
    virtual int find(Type);
    virtual Type min();
    virtual Type max();

protected:
    void swap(int,int);
    void init(const Type*, int);

    int size;  
    Type *ia;
};

#endif
