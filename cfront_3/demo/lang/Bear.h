/*ident	"@(#)cls4:demo/lang/Bear.h	1.1" */
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
#ifndef BEAR_H
#define BEAR_H

#include "ZooAnimal.h"
#include <iostream.h>

class Bear : public ZooAnimal {
public:
    Bear( char *s = "Bear", ZooLocs loc = BEAR, 
          char *sci = "Ursidae" );
    ~Bear() { delete sciName; }
    void print( ostream& );
    void isA( ostream& );
protected:
    char *sciName; // scientific name
    ZooLocs zooArea;  
};

#endif
