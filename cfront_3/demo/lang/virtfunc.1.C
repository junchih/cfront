/*ident	"@(#)cls4:demo/lang/virtfunc.1.C	1.1" */
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
    cout << "Invocation by a ZooAnimal object:\n"
         << circus << "\n";

    cout << "\nInvocation by a Bear object:\n"
         << yogi << "\n";

    cout << "\nInvocation by a Panda object:\n"
         << yinYang << "\n";

    return 0;
}
