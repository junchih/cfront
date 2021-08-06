/*ident	"@(#)cls4:demo/lang/virtfunc.0.C	1.1" */
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
#include "Bear.h"

main() {
    Bear yogi ( "cartoon Bear", BEAR, 
                "ursus cartoonus" );
    ZooAnimal circus( "circusZooAnimal" );
    ZooAnimal *pz;

    pz = &circus;
    cout << "virtual: ZooAnimal::print()\n";
    pz->print( cout ); 

    pz = &yogi;
    cout << "\nvirtual: Bear::print()\n";
    pz->print( cout ); 

    cout << "\nnonvirtual: ZooAnimal::print()\n";
    cout << "note: isA() is invoked virtually\n";
    pz->ZooAnimal::print( cout );

    return 0;
}
