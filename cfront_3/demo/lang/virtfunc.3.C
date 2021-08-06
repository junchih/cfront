/*ident	"@(#)cls4:demo/lang/virtfunc.3.C	1.1" */
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
#include "Panda.h"

ZooAnimal circus( "circusZooAnimal" );
Bear yogi("cartoon Bear",BEAR,"ursus cartoonus");
Panda yinYang("Yin Yang",1001,"Giant Panda");

main() {
    ZooAnimal *pz = &yinYang;
    cout << "Nonvirtual invocation of Panda::isA():\n";
    ((Panda*)pz) ->Panda::isA( cout );

    pz = &yogi;
    cout << "\nNonvirtual invocation of Bear::isA():\n";
    ((Bear*)pz) ->Bear::isA( cout );

    return 0;
}
