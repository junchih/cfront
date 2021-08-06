/*ident	"@(#)cls4:demo/lang/thisPtr.C	1.1" */
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
#include "Screen.h"
#include <iostream.h>

main() {
  cout << "Demo :: use of ``this'' pointer\n\n";

  Screen x(3,3);
  Screen y(3,3);

  // if equal, return 1
  cout << "isEqual( x, y ): (>1<) " 
       << x.isEqual(y) << "\n";

  y.reSize( 6, 6 ); // double it

  // let's see results
  cout << "isEqual( x, y ): (>0<) " 
       << x.isEqual(y) << "\n";

  // draw a line on the Y axis
  y.lineY(1,1,6,'*').lineY(1,6,6,'*');

  // draw a line on the X axix
  y.lineX(1,2,4,'*').lineX(6,2,4,'*').move(3,3);

  // write to screen and display
  y.set("hi").lineX(4,3,2,'^').display();

  // x and y equal in size, but not content
  x.reSize( 6, 6 );
  cout << "\n\nisEqual( x, y ): (>0<) " 
       << x.isEqual(y) << "\n";

  // now, both are equal
  x.copy( y );
  cout << "isEqual( x, y ): (>1<) " 
       << x.isEqual(y) << "\n";

  return 0;
}
