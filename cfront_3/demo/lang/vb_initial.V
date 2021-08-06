Endangered()
ZooAnimal( 4096 )
Herbivore()
Raccoon() val==1
Bear() val==1
Panda() val==1


Demo: 
	(1) Initialization of Virtual Base Class
	(2) Order of Construct and Destructor Calls


Static constructor: default Panda() constructor
ZooAnimal base of Panda explicitly initialized: 4096
note: will appear before Demo banner ...

Panda(10) constructor for local class object
ZooAnimal base of Panda initialized by default: 1
note: in both cases, explicit Bear and Raccoon
	initializations of ZooAnimal are ignored

Endangered()
ZooAnimal() val==1
Herbivore()
Raccoon( 30 )
Bear( 20 )
Panda( 10 )


Destructors for local class object:
Followed by destructors for static class object

~Panda() val==10
~Bear() val==20
~Raccoon() val==30
~Herbivore()
~ZooAnimal() val==1
~Endangered()

~Panda() val==1
~Bear() val==1
~Raccoon() val==1
~Herbivore()
~ZooAnimal() val==4096
~Endangered()
