/*ident	"@(#)cls4:demo/lang/array.2.C	1.1" */
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
#include "Array_S.C"
#include "try_array.C"
#include "String.h"

main() 
{
    static int ia[10] = { 12,7,14,9,128,17,6,3,27,5 };
    static String sa[7] = { "Eeyore", "Pooh", "Tigger", 
	"Piglet", "Owl", "Gopher", "Heffalump" };

    Array_Sort<int> iA(ia,10);
    Array_Sort<String> SA(sa,7);

    cout << "template Array_Sort<int> class\n" << endl;
    try_array(iA);

    cout << "template Array_Sort<String> class\n" << endl;
    try_array(SA);

    return 0;
}
