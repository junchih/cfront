/*ident	"@(#)cls4:demo/lang/ZooAnimal.h	1.1" */
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
#ifndef ZOO_ANIMAL_H
#define ZOO_ANIMAL_H

#include <iostream.h>

class ZooAnimal;
extern ostream& operator<<(ostream&, ZooAnimal&);
enum ZooLocs { ZOOANIMAL, BEAR, PANDA };

class ZooAnimal {
    friend void print( ZooAnimal*, ostream& = cout );
public:
    ZooAnimal( char *s = "ZooAnimal" );
    virtual ~ZooAnimal() { delete name; }
    void link( ZooAnimal* );
    virtual void print( ostream& );
    virtual void isA( ostream& );
protected:
    char *name;
    ZooAnimal *next;
};

#endif
