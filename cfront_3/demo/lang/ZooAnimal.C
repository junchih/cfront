/*ident	"@(#)cls4:demo/lang/ZooAnimal.C	1.1" */
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
#include "ZooAnimal.h"
#include <string.h>

ZooAnimal::ZooAnimal( char *s ) : next( 0 ) 
{
    name = new char[ strlen(s) + 1 ];
    strcpy( name, s );
}

void ZooAnimal::link( ZooAnimal *za )
{
    za->next = next;
    next = za;
}

void ZooAnimal::isA( ostream& os )
{
    os << "ZooAnimal name: " 
       << name << "\n";
}

void ZooAnimal::print( ostream& os )
{
    isA( os ); // virtual invocation
}

ostream&
operator <<( ostream& os, ZooAnimal& za )
{
    za.print( os );
    return os;
}
