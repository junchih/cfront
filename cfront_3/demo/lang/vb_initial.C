/*ident	"@(#)cls4:demo/lang/vb_initial.C	1.1" */
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
    ZooAnimal() : val( 1 ) 
	{ cout << "ZooAnimal() val=="<< val << endl;}
    ZooAnimal( int i ) : val( i ) 
	{ cout << "ZooAnimal( " << val << " )\n"; }
    virtual ~ZooAnimal() { cout << "~ZooAnimal() val==" << val << endl; }
protected:
    int val;
};

class Bear : public virtual ZooAnimal { 
public: 
    Bear() : ZooAnimal( 1024 ), val( 1 )
	{ cout << "Bear() val==" << val << endl; }
    Bear( int i ) : ZooAnimal( i ), val( i )
	{ cout << "Bear( " << val << " )\n"; }
    ~Bear() { cout << "~Bear() val==" << val << endl; }
protected:
    int val;
};

class Raccoon : public virtual ZooAnimal { 
public: 
    Raccoon() : ZooAnimal( 2048 ), val( 1 )
	{ cout << "Raccoon() val==" << val << endl; }
    Raccoon( int i ) : ZooAnimal( i ), val( i )
	{ cout << "Raccoon( " << val << " )\n"; }
    ~Raccoon() { cout << "~Raccoon() val==" << val << endl; }
protected:
    int val;
};

class Endangered { 
public: 
    Endangered() { cout << "Endangered()\n"; }
    virtual ~Endangered() { cout << "~Endangered()\n"; }
};

class Herbivore { 
public: 
    Herbivore() { cout << "Herbivore()\n"; }
    ~Herbivore() { cout << "~Herbivore()\n"; }
};

class Panda : public virtual Endangered, public Herbivore, 
	      public Raccoon, public Bear { 
public: 
    Panda() : ZooAnimal( 4096 ), val( 1 )
	{ cout << "Panda() val==" << val << endl; }
    Panda( int i ) : Bear( i*2 ), Raccoon( i*3 ),  val( i )
	{ cout << "Panda( " << val << " )\n"; }
    ~Panda() { cout << "\n~Panda() val==" << val << endl; }
protected:
    int val;
};

Panda yinYang;

main() {
    cout << "\n\nDemo: \n\t(1) Initialization of Virtual Base Class"
         << "\n\t(2) Order of Construct and Destructor Calls\n";

    cout << "\n\nStatic constructor: default Panda() constructor\n"
	 << "ZooAnimal base of Panda explicitly initialized: 4096\n"
         << "note: will appear before Demo banner ...\n\n" 
         << "Panda(10) constructor for local class object\n"
         << "ZooAnimal base of Panda initialized by default: 1\n"
         << "note: in both cases, explicit Bear and Raccoon\n"
         << "\tinitializations of ZooAnimal are ignored\n\n";

    Panda lingLing( 10 );

    cout << "\n\nDestructors for local class object:\n"
         << "Followed by destructors for static class object\n";
    return 0;
}
