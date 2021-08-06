/*ident	"@(#)cls4:demo/lang/new_del.C	1.1" */
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
#include "String.h"
#include "StringList.h"

// maintain a pointer table indexed by length
const int maxLen = 25;
StringList *stbl[ maxLen ];

main() 
{ // read in and sort strings by length
     const int inBuf = 512;
     char st[ inBuf ];
     StringList *p;

     while ( cin >> st ) {
	// StringList::operator new()
        p = new StringList( st );
        int sz = p->getLen();
        if ( sz >= maxLen ) 
             continue;
        p->next = stbl[ sz ];
        stbl[ sz ] = p;
     }

     for ( int i = maxLen - 1; i > 0; --i ) {
         StringList *tp;
         p = stbl[ i ];
         while ( p != 0 ) {
            cout << *p << "\n";
            tp = p;
            p = p->next;
	    // StringList::operator delete()
            delete tp;
	} 
    } 

    return 0;
}
