/*ident	"@(#)cls4:demo/lang/Panda.h	1.1" */
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
#ifndef PANDA_H
#define PANDA_H

#include "Bear.h"
#include <iostream.h>

class Panda : public Bear {
public:
    Panda( char *nm, int room, char *s = "Panda",
           char *sci = "Ailuropoda Melaoleuca",
           ZooLocs loc = PANDA );
    void print( ostream& );
    void isA( ostream& );
    ~Panda() { delete indName; }
protected:
    char *indName; // name of individual animal
    int cell;
};

#endif
