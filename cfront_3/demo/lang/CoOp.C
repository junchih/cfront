/*ident	"@(#)cls4:demo/lang/CoOp.C	1.1" */
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

#include "CoOp.h"
double CoOp::costPerShare = 19.99;

void CoOp::raiseCost(double incr) 
{ 
    costPerShare += incr; 
}

double CoOp::monthlyMaint() 
{
    return( costPerShare * shares );
}

#include <string.h>
CoOp::CoOp( int sh, char *nm ) {
    shares = sh;
    owner = new char[ strlen( nm ) + 1 ];
    strcpy( owner, nm );
}
