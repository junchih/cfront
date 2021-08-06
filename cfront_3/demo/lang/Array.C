/*ident	"@(#)cls4:demo/lang/Array.C	1.1" */
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
#ifndef ARRAY_C
#define ARRAY_C

#include "Array.h"

#ifdef assert
#undef assert
#endif
#ifdef _assert
#undef _assert
#endif

#ifdef NDEBUG

#define assert(e) ((void)0)

#else

#ifndef __SYSENT_H
#include <sysent.h>
#endif

#ifndef __STDLIB_H
#include <stdlib.h>
#endif

#ifndef IOSTREAMH
#include <iostream.h>
#endif

#if defined(__STDC__)
#define assert(EX) (void)((EX) || ((cerr << "Assertion failed: " # EX ", file " << __FILE__ << ", line " << __LINE__ << endl), abort(), 0))
#else
#define assert(EX) (void)((EX) || ((cerr << "Assertion failed: EX, file " << __FILE__ << ", line " << __LINE__ << endl), abort(), 0))
#endif
#endif

#define _assert(e) assert(e)

template <class Type> ostream& 
operator<<( ostream& os, Array<Type>& ar) 
{
    ar.print(os); 
    return os; 
}

template <class Type> void
Array<Type>::init(const Type *array, int sz)
{
    ia = new Type[size = sz]; 
    assert( ia != 0 );

    for (int ix = 0; ix < size; ++ix)
         ia[ix] = (array!=0) ? array[ix] : (Type)0;
}


template <class Type> 
Array<Type>::Array(int sz) { init(0,sz); }

template <class Type> 
Array<Type>::Array(Type *ar, int sz) { init(ar,sz); }

template <class Type> 
Array<Type>::Array(const Array<Type> &iA) 
    { init(iA.ia,iA.size); }

template <class Type> Array<Type>&
Array<Type>::operator=(const Array<Type> &iA)
{
    if (this == &iA) return *this;
    delete ia; 
    init( iA.ia, iA.size );
    return *this;
}

template <class Type> void 
Array<Type>::grow()
{ 
  Type *oldia = ia;
  int oldSize = size;

  size += size/2 + 1; 
  ia = new Type[size];
  assert( ia != 0 );

  for (int i=0; i<oldSize; ++i) ia[i] = oldia[i];
  for (; i<size; ++i) ia[i] = 0;

  delete oldia;
}

template <class Type>
Type Array<Type>::min() 
{ 
    Type min_val = ia[0];
    for (int i=1; i<size; ++i)
         if (min_val > ia[i]) min_val = ia[i];
    return min_val;
}

template <class Type>
Type Array<Type>::max() 
{ 
    Type max_val = ia[0];
    for (int i=1; i<size; ++i)
 	 if (max_val < ia[i]) max_val = ia[i];
    return max_val;
}		

template <class Type>
int Array<Type>::find(Type val) 
{ 
    for (int i=0; i<size; ++i)
         if (val == ia[i]) return i;
    return not_found;
}		

template <class Type>
void Array<Type>::swap(int i, int j)
{ 
     Type tmp = ia[i];
     ia[i] = ia[j];
     ia[j] = tmp;
}

template <class Type>
void Array<Type>::sort(int low, int high)
{ 
     if (low < high) {
	  int lo = low;
	  int hi = high + 1;
	  Type elem = ia[low];
			
          for (;;) {
	      // while (ia[++lo] <= elem) ;
	      while (ia[++lo] < elem) ;
	      while (ia[--hi] > elem) ;
				
	      if (lo < hi)
		 swap(lo,hi);
	      else break;
	   }  

	swap(low,hi);
	sort(low,hi-1);
	sort(hi+1,high);
	} 
}

template <class Type>
void Array<Type>::print(ostream& os) 
{
const int lineLength = 6; 

     os << "( " << size << " )< ";
     for (int i = 0; i < size; ++i) { 
        if (i % lineLength == 0 && i) os << "\n\t"; 
        os << ia[ i ];

        if (i%lineLength != lineLength-1 && i != size-1)
             	os << ", ";
     }
     os << " >\n";
}

#endif
