/*ident	"@(#)cls4:demo/lang/String.h	1.1" */
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
#ifndef STRING_H
#define STRING_H

#include <iostream.h>
#include <string.h>

class String;
class StringIterator {
public:
	StringIterator(String& s) { ps = &s; index = 0; }
	char operator()();
private:
	String *ps;
	int index;
};

const int String_size = 1024; // arbitrary constant

class String {
    friend ostream& operator <<(ostream&,String&);
    friend istream& operator >>(istream&,String&);
    friend String operator+(String&,String&);
    friend class StringIterator;
public:
    String(int);
    String(char*);
    String(const String&);
    String();
    ~String() { delete str; }

    String& operator()(int,int);
    char& operator[](int);
    String& operator=(const char*);
    String& operator=(const String&);
    String& operator+=(const String&);
    int operator==(const String &s); 

    int operator==(const char *s) { return (strcmp(str,s)==0); }
    int operator!() { return( len == 0 ); } 
    void print() { cout<< "< " << len << ", " << str << " >\n";}
    inline void checkBounds(int);
    int getLen() { return len; }
    int operator <(String& s);
    int operator >(String& s);
    void set(char*);
private:
    int len;
    char *str;
};

#endif
