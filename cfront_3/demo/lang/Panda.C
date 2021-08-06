/*ident	"@(#)cls4:demo/lang/Panda.C	1.1" */
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
#include "Panda.h"
#include <string.h>

Panda::Panda ( char *nm, int room, char *s,
               char *sci, ZooLocs loc )
     : Bear( s, loc, sci ), cell( room ) {
    indName = new char[ strlen(nm) + 1 ];
    strcpy( indName, nm );
}

void Panda::isA( ostream& os ) 
{
    Bear::isA( os );
    os << "\twe call our friend:\t";
    os << indName << "\n";
}

void Panda::print( ostream& os ) 
{
    Bear::print( os );
    os << "\tRoom Location:\t";
    os << cell << "\n";
}
