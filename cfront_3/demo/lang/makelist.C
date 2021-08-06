/*ident	"@(#)cls4:demo/lang/makelist.C	1.1" */
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
Panda rocky("Rocky",943,"Red Panda","Ailurus fulgens");

ZooAnimal *makeList( ZooAnimal *ptr )
{
    // for simplicity, hand code list
    ptr = &yinYang;
    ptr->link( &circus );
    ptr->link( &yogi );
    ptr->link( &rocky );
    return ptr;
}
