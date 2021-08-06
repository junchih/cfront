/*ident	"@(#)cls4:demo/lang/Array_S.C	1.1" */
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
#include "Array_S.h"
#include "Array.C"

template <class Type>
Array_Sort<Type>::
Array_Sort(const Array_Sort<Type> &as)
    : Array<Type>( as )
{ 
    // as.check_bit() does not work!
    if ( as.is_dirty() )
	 sort( 0, size-1 );
    clear_bit();
}  

template <class Type>
Array_Sort<Type>::
Array_Sort(int sz)
        : Array<Type>( sz )
	{ clear_bit(); }

template <class Type> void
Array_Sort<Type>::grow()
{ 
    Array<Type>::grow();
    sort( 0, size-1 );
    clear_bit();
}  

template <class Type>
int Array_Sort<Type>::find(Type val) 
{ 
     int low = 0;
     int high = size-1;
     check_bit();

     while ( low <= high )
     { 
          int mid = (low + high)/2;
          if (val == ia[mid])
               return mid;
          if (val < ia[mid])
               high = mid-1;
          else low = mid+1;
      }   

      return not_found;
}  
