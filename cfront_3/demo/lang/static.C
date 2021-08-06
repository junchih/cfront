/*ident	"@(#)cls4:demo/lang/static.C	1.1" */
/*#########################################################################
#                       Copyright (c) 1989 AT&T
#                         All Rights Reserved   
#
#                THIS IS PROPRIETARY SOURCE CODE OF AT&T
#       
#                     This code has been published in
#                      C++ Primer by Stanley Lippman
#                    Addison_Wesley Publishing Company
#
#########################################################################*/
#include <iostream.h>
#include "CoOp.h"

int canAfford( double affordShare ) {
    enum { LOCAL_FALSE, LOCAL_TRUE };

    // no CoOp class objects defined
    if ( affordShare >= CoOp::getCost() ) 
	 return LOCAL_TRUE;
    else return LOCAL_FALSE;
}

main() {
    double affordShare = 29.95;

    cout << "Demo: static class member functions\n\n";

    if ( canAfford( affordShare ) )
    {
	// pointer to static class member is 
        // declared as non-member pointer
	void (*psf)(double) = &CoOp::raiseCost;
        psf( affordShare );

	CoOp studio( 250, "dan" );
        if ( affordShare < studio.getCost() )
             cout << "oops, price must have risen since\
 the if clause!\n"; 
    	    
    }
    return 0;
}
