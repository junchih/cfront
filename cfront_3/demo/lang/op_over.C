/*ident	"@(#)cls4:demo/lang/op_over.C	1.1" */
/*#########################################################################
#                       Copyright (c) 1991 AT&T
#                         All Rights Reserved   
#
#                THIS IS PROPRIETARY SOURCE CODE OF AT&T
#       
#                     This code has been published in
#                         C++ Primer, 2nd Edition 
#			    by Stanley Lippman
#                    Addison_Wesley Publishing Company
#
#########################################################################*/
#include <iostream.h>
#include "String.h"
#include <ctype.h>

const int LINESIZE = 40;
enum {BLANK=' ',PERIOD='.',COMMA = ',',SEMI=';',COLON=':'};

main() {
    String inBuf;
    int lineSize = 0;

    // operator>>( istream&, String& )
    while ( cin >> inBuf )
    {
        char ch;
	int index = 0;
	StringIterator next(inBuf);

        while (ch = next())
	{
	    switch (ch) {
		default:
		{
		    if (isalpha(ch) && isupper(ch))
			inBuf[index] = tolower(ch);
		    break;
		}
		case PERIOD:
		case COMMA:
		case SEMI:
		case COLON:
		    inBuf[index] = BLANK;
		    break;
	    }
	    ++index; ++lineSize;
	}
	if ( lineSize >= LINESIZE )
	{
	    cout << endl;
	    lineSize = 0;
        }
        cout << inBuf << " ";
    }
    cout << endl;
    return 0;
}
