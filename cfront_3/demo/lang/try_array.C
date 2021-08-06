/*ident	"@(#)cls4:demo/lang/try_array.C	1.1" */
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
#include "Array.h"

template <class Type>
void try_array( Array<Type> &iA ) 
{ // exercise the array class
    cout << "try_array: initial array values:\n";
    cout << iA << endl;

/*
    Type find_val = iA[iA.getSize()-1];
*/
    iA[iA.getSize()-1] = iA.min(); 

    int mid = iA.getSize()/2;
    iA[0] = iA.max(); iA[mid] = iA[0];
    cout << "try_array: after assignments:\n";
    cout << iA << endl;

    Array<Type> iA2 = iA; 
    iA2[mid/2] = iA2[mid];
    cout << "try_array: memberwise initialization\n";
    cout << iA << endl;

    iA = iA2;
    cout << "try_array: after memberwise copy\n";
    cout << iA << endl;

    iA.grow();
    cout << "try_array: after grow\n";
    cout << iA << endl;

    /* commented out since Demo tests depend on ``correctness''
     * and the ability of diff to compare exactly -- remove if
     * programs are run by hand -- more interesting!!! 

    int index = iA.find(find_val);
    cout << "value to find: " << find_val;
    cout << "\tindex returned: " << index << endl;
    Type value = iA[index];
    cout << "value found at index: " << value << endl;
    */
}
