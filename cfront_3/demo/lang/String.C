/*ident	"@(#)cls4:demo/lang/String.C	1.1" */
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
#include <string.h>

String::String()
{
	len = 0;
	str = 0;
}

String::String( char *s ) 
{
	len = strlen( s );
	str = new char[ len + 1 ];
	strcpy( str, s );
}

String::String( int l )
{
	len = l;
	str = 0;
}

String::String( const String& s )
{
	len = s.len;
	if (s.str==0) { str = 0; return; }
	str = new char[ len + 1 ];
	strcpy( str, s.str );
}

String& String::operator=( const String& s )
{
    if (this == &s) return *this;
    delete str;
    len = s.len;
    if (s.str == 0) { str = 0; return *this; }
    str = new char[ len + 1 ];
    strcpy( str, s.str );
    return *this;
}

int String::operator==(const String &s) 
{
    if (len != s.len) return 0;
    return (strcmp(str,s.str)==0); 
}

char&
String::operator[]( int elem )
{
    checkBounds( elem );
    return str[ elem ];
}

#include <stdlib.h>
void String::checkBounds( int elem )
{
    if ( elem < 0 || elem >= len )
    {
	cerr << "\nString Array Out of Bounds!! index: " << elem
	     << " string length (0-"
	     << len-1 << ")\n";	
	exit( -1 );
    }
}

#include <iomanip.h>
istream& operator>>( istream &io, String &s )
{
    char inBuf[ String_size ]; 
    io >> setw( String_size-1 ) >> inBuf;
    s = inBuf; // String::operator=(char*);
    return io;
}

ostream& operator<<( ostream& os, String& s )
{
    if (!s) return os << "<empty>";
    return os << s.str;
}

String& String::operator=( const char *s )
{
    if (s == 0) { len = 0; str = 0; return *this; }
    len = strlen( s );
    delete str;
    str = new char[ len + 1 ];
    strcpy( str, s );
    return *this;
}

String& String::operator()(int pos, int cnt) 
{
    if ( pos < 0 || pos > len-1 || cnt <= 0 )
	{
	    cerr << "?? String::operator( " << pos << ", " 
		 << cnt << " ) invalid argument(s)\n"; 
	    exit(-1);
	}

    if ( cnt + pos - 1 > len ) {
	cerr << "warning: String::operator( " << pos 
		 << ", " << cnt << " ) substring truncation "
		 << str << endl;
	cnt = len - pos + 1;
    }

    String *ps = new String(cnt+1);
    for ( int i = pos, j = 0; j < cnt; ++i, ++j ) 
	ps->str[j] = str[i];
    ps->str[cnt] = '\0';

    return *ps;
}

char StringIterator::operator()() 
{
    char ch = ps->str[index];
    index = index == ps->len 
	? 0 : index + 1;
    return ch;
}

String&
String::operator+=( const String &s )
{
    len += s.len;
    char *p = new char[len+1];
    strcpy(p,str);
    strcat(p,s.str);
    delete str;
    str=p;
    return *this;
}

String
operator+(const String &s1, const String &s2 )
{
    String result = s1;
    result += s2; 
    return result;
}

int String::operator<(String& s) { 
	if (s.len == 0) return 0;
	if (len == 0) return 1;
	return(strcmp(str,s.str)<0) ? 1: 0; 
}

int String::operator>(String& s) { 
	if (len == 0) return 0;
	if (s.len == 0) return 1;
	return(strcmp(str,s.str)>0) ? 1: 0; 
}
