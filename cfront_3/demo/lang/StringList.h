/*ident	"@(#)cls4:demo/lang/StringList.h	1.1" */
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
#include "String.h"
#include <iostream.h>
#include <stddef.h>

class StringList {
    friend ostream& operator<<(ostream&, StringList&);
public:
	int getLen();
	StringList *next;
public:
	StringList( char* );
        StringList& operator=( const StringList& );
	void *operator new(size_t);
	void operator delete( void*, size_t );	
private:
	enum { StringChunk = 24 };
	String entry;
	int len;
	static StringList *freeStore;
};
