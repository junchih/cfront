/*ident	"@(#)cls4:demo/lang/virtfunc.4.C	1.1" */
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

extern ZooAnimal *makeList( ZooAnimal* );
ZooAnimal *headPtr = 0;

main() {
  cout<< "A Program to Illustrate Virtual Functions\n";
  headPtr = makeList( headPtr );
  print( headPtr );

  return 0;
}
