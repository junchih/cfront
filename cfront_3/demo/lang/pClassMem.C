/*ident	"@(#)cls4:demo/lang/pClassMem.C	1.1" */
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
#include "Screen.h"

main() 
{ 
  cout << "Demo: Pointers to class member functions\n\n";
  Screen x(3,3);
  int sz = x.getHeight() * x.getWidth();

      // see Screen.h for details
      // invokes Screen::move(CursorMovements)
      x.move( HOME ); 
      for ( int i = 0; i <= sz; ++i ) 
            x.stats().move( FORWARD );

      cout << "\n\n";

      x.move( BOTTOM );
      for ( i = 0; i <= sz; ++i ) 
            x.stats().move( BACK );

      cout << "\n\n";

      typedef Screen& (Screen::*Action)();
      Action pmf = &Screen::home;
      Screen *ps = &x;

      (x.*pmf)(); 
      for ( i = 0; i <= sz; ++i ) {
            pmf = &Screen::stats;
            (x.*pmf)();
	    pmf = &Screen::forward;
	    (ps->*pmf)();
      }	

      return 0;
}
