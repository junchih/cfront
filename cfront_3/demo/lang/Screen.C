/*ident	"@(#)cls4:demo/lang/Screen.C	1.1" */
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
#include <stdlib.h>

void Screen::checkRange( int x, int y )
{ // verify range
     if ( x < 1 || x > height ||
          y < 1 || y > width )
     {
       cerr<< "Screen(" << height << "," << width
           << "): value out of range: move("
           << x << "," << y << ")\n";
       exit( -1 );
     }
}

int Screen::col() 
{ // return current column
  int pos = cursor - screen + 1; 
  return ((pos + width - 1) % width ) + 1;
}

int Screen::row() 
{ // return current row
  int pos = cursor - screen + 1; 
  return ( pos + width - 1 ) / width;
} 

int Screen::remainingSpace() 
{ // current position is no longer remaining
  int sz = width*height;
  return( screen + sz - cursor - 1 );
}

Screen& Screen::move( int x, int y )
{ // move cursor absolute position
    checkRange( x, y ); // valid address?
    int row = ( x-1 ) * width; // row location
    cursor = screen + row 
             + y-1; // column location    
    return *this;
}

Screen& Screen::back()
{ // move cursor backward one screen element

    // check for top of screen; wraparound
    if ( cursor == screen )
	bottom();
    else
	--cursor;
    return *this;
}

Screen& Screen::bottom ()
{
    int sz = width*height - 1;
    cursor = screen + sz;
    return *this;
}

enum { BELL = '\007' };
Screen& Screen::up()
{ // move cursor up one row of screen
  // do not wraparound; rather, ring bell
    
    if ( row() == 1 ) // at top?
	cout.put( BELL );
    else
	cursor -= width;
    return *this;
}

Screen& Screen::down()
{
    if ( row() == height ) // at bottom?
	cout.put( BELL );
    else
	cursor += width;
    return *this;
}

Screen& Screen::set( char *s )
{ // write string beginning at screen element

    int space = remainingSpace();
    int len = strlen( s );
    if ( space < len ) {
        cerr << "Screen: warning: truncation: "
             << "space: " << space
	     << "string length: " << len << "\n";
	len = space;
    }

    for ( int i = 0; i < len; ++i ) 
	*cursor++ = *s++;
    return *this;
}

Screen& Screen::set( char ch ) 
{
    if ( ch == '\0' )
        cerr << "Screen: warning: "
             << "null character (ignored).\n";
    else *cursor = ch; 
    return *this;
}

int Screen::isEqual( char *s )
{ // yes? return 1; otherwise, 0

    int len = strlen( s );
    if ( remainingSpace() < len )
	return 0;

    char *p = cursor;
    for ( int i = 0; i < len; ++i )
	if ( *p++ != *s++ )
	    return 0;

    return 1;
}

int Screen::isEqual( Screen& s )
{ 
    // first, are they physically unequal?
    if ( width != s.width || height != s.height )
	return 0;

    // do both share the same screen?
    char *p = screen;
    char *q = s.screen;
    if ( p == q ) return 1;

    // be careful not to walk off the Screens
    while ( *p && *p++ == *q++ );

    if ( *p ) // loop broke on not equal
	return 0;

    return 1;
}

Screen& Screen::clear( char bkground )
{ // reset the cursor and clear the screen
     char *p = cursor = screen;

     while ( *p )
	*p++ = bkground;

    return *this; // return invoking object
}

char Screen::get( int x, int y )
{
    move( x, y ); // position cursor
    return get();
}

Screen& Screen::copy( Screen& s )
{ // copy one Screen object with another

    // free up existing storage, if any
    if ( screen != 0 )
	delete screen;

    height = s.height;
    width = s.width;

    screen = cursor = new char[ height * width + 1 ];
    strcpy( screen, s.screen );
    return *this;
}

Screen::Screen( int _height, int _width, char bkground )
{
    int sz;

    // initialize data members
    height = _height;
    width = _width;
    cursor = screen = new char[ (sz = height*width) + 1 ];

    char *endptr = screen + sz;
    char *ptr = screen;
    while ( ptr != endptr )
	*ptr++ = bkground;
    *ptr ='\0'; 
}

Screen& Screen::forward() 
{ // advance cursor one screen element

    ++cursor;
    if (! (*cursor)) home();
    return *this;
}

Screen& Screen::stats()
{
     cout << "row: " << row()<< "\t";
     cout << "col: " << col()<< "\t";
     cout << "rm: " << remainingSpace()<< "\n";
    return *this;
}

Screen& 
Screen::lineX( int x, int y, // x,y coordinates
               int len, char ch)
{ // provide straight line along x-axis 

    move( x, y ); // move to beginning of line

    // now, draw the line of size len  
    for ( int i = 0; i < len; ++i )
	set( ch ).forward();

    return *this;
}

Screen& 
Screen::lineY( int x, int y,
               int len, char ch)
{ // provide straight line along y-axis 
     move( x, y );
     for ( int i = 0; i < len; ++i )
	 set(ch).down();

     return *this;
}

Screen& Screen::display()
{
    char *p;
    for ( int i = 0; i < height; ++i ) 
    {   // for each row
        cout << "\n"; 
        int offset = width * i; // row position
        for ( int j = 0; j < width; ++j ) 
	{   // for each column, write element
	    p = screen + offset + j;
	    cout.put( *p ); 
	}
    }
    return *this;
}

Screen& Screen::reSize( int h, int w, char bkground )
{ // reSize a screen to height h and width w

    Screen *ps = new Screen( h, w, bkground );
    char *pNew = ps->screen;

    // Is this screen currently allocated?
    // If so, copy old screen contents to new
    if ( screen ) 
    {
	char *pOld = screen;
	while ( *pOld && *pNew )
	     *pNew++ = *pOld++;
	delete screen;
     }

     while ( *pNew )
        *pNew++ = bkground;

     *this = *ps; // replace Screen object
     return *this;
}

ostream& operator<<( ostream& os, Screen& s ) 
{ 
    os << "\n<" << s.height
       << "," << s.width << ">";
    
    char *p = s.screen;
    while ( *p )
       os.put( *p++ );
  
    return os;
}

enum {LBRAC = '<', RBRAC = '>', COMMA = ','};
istream& operator>>( istream& os, Screen& s ) 
{ // read Screen object output by << Screen
    int wid, hi;
    char ch;

    // format verification not shown
    // <hi,wid>screenDump
    os >> ch;  // '>'
    os >> hi;  // get height
    os >> ch;  // ','
    os >> wid; // get width
    os >> ch;  // '<'

    // don't modify s until sure format valid
    if ( s.screen ) // return to free store
         delete s.screen;

    int sz = hi * wid;
    s.height = hi; s.width = wid;
    s.cursor = s.screen = new char[ sz + 1 ];

    char *endptr = s.screen + sz;
    char *ptr = s.screen;
    while ( ptr != endptr )
       os.get( *ptr++ );
    *ptr = '\0';    

    return os;
}

typedef Screen& (Screen::*Action)();
Action Menu[] = {
    &Screen::home,
    &Screen::forward,
    &Screen::back,
    &Screen::up,
    &Screen::down,
    &Screen::bottom
};

Screen& Screen::move( CursorMovements cm ) 
{
    (this->*Menu[ cm ])();
    return *this;
} 
