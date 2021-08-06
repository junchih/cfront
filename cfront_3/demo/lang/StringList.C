/*ident	"@(#)cls4:demo/lang/StringList.C	1.1" */
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
#include <stddef.h>
#include "StringList.h"

StringList *StringList::freeStore = 0;

StringList::StringList( char *s )
          : entry( s ), next( 0 ) { }

int
StringList::getLen()
{
    return entry.getLen();
}

ostream&
operator <<( ostream& os, StringList& s )
{
    return ( os << s.entry );
}

void *StringList::operator new( size_t size )
{
	register StringList *p;
		
	// if the free store is exhausted
	// grab a new chunk of memory
	if ( !freeStore ) {
	    long sz = StringChunk * size;
	    freeStore = p =
		// the global new operator
	        (StringList *)new char[ sz ];

	    // initialize the StringList freeStore
	    for ( ; p != &freeStore[ StringChunk-1 ];
		    p->next = p+1, p++ ) ; 
	    p->next = 0;
	}

	p = freeStore;
	freeStore = freeStore->next;
	return p;
}

void StringList::operator delete( void *p, size_t )
{
    // restore p to freeStore
    ((StringList*)p)->next = freeStore;
    freeStore = (StringList *)p;
}
