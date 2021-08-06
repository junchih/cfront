/*ident	"@(#)cls4:demo/lang/array.3.C	1.1" */
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
#include "Array_RC_S.C"
#include "try_array.C"
#include "String.h"

main() 
{
    static int ia[] = { 12,7,14,9,128,17,6,3,27,5 };
    static String sa[] = { "Eeyore", "Pooh", "Tigger", 
	"Piglet", "Owl", "Gopher", "Heffalump" };

    Array_RC_S<int> iA(ia,sizeof(ia)/sizeof(int));
    Array_RC_S<String> SA(sa,sizeof(sa)/sizeof(String));

    cout << "template Array_RC_S<int> class\n" << endl;
    try_array(iA);

    cout << "template Array_RC_S<String> class\n" << endl;
    try_array(SA);

    return 0;
}
