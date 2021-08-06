/*ident	"@(#)cls4:demo/lang/print.C	1.1" */
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
#include "ZooAnimal.h"

void print( ZooAnimal *pz, ostream &os )
{
    while ( pz ) {
        pz->print( os );
        os << "\n";
        pz = pz->next;
    }
}
