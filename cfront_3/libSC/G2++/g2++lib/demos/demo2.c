/*ident	"@(#)G2++:g2++lib/demos/demo2.c	3.1" */
/******************************************************************************
*
* C++ Standard Components, Release 3.0.
*
* Copyright (c) 1991, 1992 AT&T and Unix System Laboratories, Inc.
* Copyright (c) 1988, 1989, 1990 AT&T.  All Rights Reserved.
*
* THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T and Unix System
* Laboratories, Inc.  The copyright notice above does not evidence
* any actual or intended publication of such source code.
*
******************************************************************************/

#include "usr.h"
#include <stream.h>

main(){
    USR u;

    while( cin >> u ){
	cout << u;
    }
    return 0;
}
