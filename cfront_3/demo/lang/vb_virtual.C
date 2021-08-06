/*ident	"@(#)cls4:demo/lang/vb_virtual.C	1.1" */
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

class ZooAnimal { 
public: 
    void virtual locate() const;
    // ...
};
void 
ZooAnimal::locate() const { 
	cout << "ZooAnimal::locate()\n"; 
}

class Bear : virtual public ZooAnimal { 
public: 
    void locate() const; 
    // ...
};
void 
Bear::locate() const { 
	cout << "Bear::locate()\n"; 
}

class Raccoon : virtual public ZooAnimal {};
class Panda : public Raccoon, public Bear {};
class GiantPanda : public Panda {
public:
    void locate() const ;
    // ...
};
void 
GiantPanda::locate() const { 
	cout << "GiantPanda::locate()\n"; 
}

void f( const ZooAnimal *za ) { za->locate(); }

main() {
    GiantPanda lingLing;
    Bear *yogi = &lingLing;
    Raccoon *rocky = &lingLing;

    cout << "Demo: Virtual Function in Virtual Base Hierarchy\n";
    cout << "\nExpected three outputs: GiantPanda::locate()\n";
    f( &lingLing ); 
    f( rocky );
    f( yogi );

    Panda pandy;
    yogi = &pandy;
    rocky = &pandy;

    cout << "\nExpected three outputs: Bear::locate()\n";
    cout << "Bear::locate() dominates ZooAnimal::locate()\n";
    cout << "(*** for explanation, see the demo ``dominate.c'' ***)\n\n";
    f( &pandy );
    f( rocky );
    f( yogi );
    return 0;
}
