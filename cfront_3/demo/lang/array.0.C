/*ident	"@(#)cls4:demo/lang/array.0.C	1.1" */
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
#include "String.h"
#include "Array.C"
#include "try_array.C"

main() 
{
    static int ia[] = { 12,7,14,9,128,17,6,3,27,5 };
    static double da[] = {12.3,7.9,14.6,9.8,128.0 };
    static String sa[] = { "Eeyore", "Pooh", "Tigger", 
	"Piglet", "Owl", "Gopher", "Heffalump" };

    Array<int> iA(ia,sizeof(ia)/sizeof(int));
    Array<double> dA(da,sizeof(da)/sizeof(double));
    Array<String> SA(sa,sizeof(sa)/sizeof(String));

    cout << "template Array<int> class\n" << endl;
    try_array(iA);

    cout << "template Array<double> class\n" << endl;
    try_array(dA);

    cout << "template Array<String> class\n" << endl;
    try_array(SA);

    return 0;
}
