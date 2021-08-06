/*ident	"@(#)cls4:demo/lang/Bear.C	1.1" */
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
#include "Bear.h"
#include <string.h>

Bear::Bear( char *s, ZooLocs loc, char *sci )
    : ZooAnimal( s ), zooArea( loc ) {
    sciName = new char[ strlen(sci) + 1 ];
    strcpy( sciName, sci );
}

void Bear::isA( ostream& os ) {
    ZooAnimal::isA( os ); // static invocation
    os << "\tscientific name:\t";
    os << sciName << "\n";
}

static char *locTable[] = {
    "The entire animal display area",  // ZOOANIMAL
    "NorthWest: B1: area Brown",       // BEAR
    "NorthWest: B1.P: area BrownSpots" // PANDA
    // ... and so on
};

void Bear::print( ostream& os ) {
    ZooAnimal::print( os ); // static invocation
    os << "\tZoo Area Location:\n\t";
    os << locTable[ zooArea ] << "\n";
}
