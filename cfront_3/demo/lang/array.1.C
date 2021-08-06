/*ident	"@(#)cls4:demo/lang/array.1.C	1.1" */
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
#include "Array_RC.C"
#include "try_array.C"

main() 
{
    static int ia[10] = { 12,7,14,9,128,17,6,3,27,5 };
    Array_RC<int> iA(ia,10);

    cout << "template Array_RC<int> class\n" << endl;
    try_array(iA);

    return 0;
}
