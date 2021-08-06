/*ident	"@(#)cls4:demo/lang/hello.C	1.1" */
/*******************************************************************************
 
C++ source for the C++ Language System, Release 3.0.  This product
is a new release of the original cfront developed in the computer
science research center of AT&T Bell Laboratories.

Copyright (c) 1991 AT&T and UNIX System Laboratories, Inc.
Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.

THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
Laboratories, Inc.  The copyright notice above does not evidence
any actual or intended publication of such source code.

*******************************************************************************/
/* successful execution indicates the stream static constructor
 * was correctly initialized.  if the executable core dumps,
 * then the munch/patch option is not working correctly.
 * check the release notes for suggestions
*/

#include <stream.h>
#include <stdlib.h>

main() 
{
	cout << "!! hello, c++: ok\n";
	exit( 0 );
}

