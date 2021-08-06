/*ident	"@(#)cls4:demo/lang/vb_domin.C	1.1" */
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
/*
 * In a virtual derivation, the most derived instance
 * of a member function ``dominates.''
 * The call of pp.locate() in f() resolves to Bear::locate() 
 * because it is the most derived instance. 
 * As an exercise, copy this file and remove the
 * virtual keyword from Raccoon and Bear --
 * the call of pp.local() is now ambiguous: both
 * ZooAnimal::locate() through Raccoon
 * and Bear::locate() are now possible
 */
#include <iostream.h>

class ZooAnimal { 
public: 
    void locate() { cout << "ZooAnimal::locate()\n"; };
    // ...
};

class Bear : virtual public ZooAnimal { 
public: 
    void locate() { cout << "Bear::locate()\n"; };
    // ...
};

class Raccoon : virtual public ZooAnimal {};
class Panda : public Raccoon, public Bear {};

void f( Panda &pp ) { pp.locate(); }
main() {
    Panda lingLing;

    cout << "Demo: Dominate Function in Virtual Base Hierarchy\n";
    f( lingLing );
    return 0;
}
