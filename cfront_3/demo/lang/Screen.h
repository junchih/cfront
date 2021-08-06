/*ident	"@(#)cls4:demo/lang/Screen.h	1.1" */
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
#ifndef SCREEN_H
#define SCREEN_H

#include <iostream.h>
#include <string.h>

enum CursorMovements { 
    HOME, FORWARD, BACK, UP, DOWN, BOTTOM 
};

class Screen {
    friend istream& 
        operator>>( istream&, Screen& );
    friend ostream& 
        operator<<( ostream&, Screen& );
public:
    Screen( int = 8, int = 40, char = '#' );
    ~Screen() { delete screen; }
    Screen& home(){ move(1,1); return *this; }
    Screen& forward();
    Screen& back();
    Screen& up();
    Screen& down();
    Screen& lineX( int, int, int, char='-' );
    Screen& lineY( int, int, int, char='|' );
    Screen& bottom();
    Screen& move( CursorMovements );
    Screen& move( int, int );

    char get() { return *cursor; }
    char get( int, int );
    Screen& set( char* );
    Screen& set( char );
    int isEqual( Screen& );
    int isEqual( char* );
    int isEqual( char ch ) { return (ch == *cursor ); }
    int getHeight() { return height; }
    int getWidth() { return width; }

    Screen& copy( Screen& );
    Screen& clear( char = '#' );
    Screen& reSize( int, int, char = '#' );
    Screen& display();
    Screen& stats();
private:
    int row();
    int col();
    int remainingSpace();
    void checkRange(int,int);
private:
    short height, width;
    char *cursor, *screen;
};

#endif
