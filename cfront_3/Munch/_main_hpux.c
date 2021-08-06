/*ident	"@(#)C++env:Munch/_main.c	1.1" */
/**************************************************************************
			Copyright (c) 1984 AT&T
	  		  All Rights Reserved  	

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T
	
	The copyright notice above does not evidence any   	
	actual or intended publication of such source code.

*****************************************************************************/
//// with patch for HP-UX 7.0 by mozart!dmm, 12/1/89
extern "C" {
extern void _main();
extern void atexit(void (*)());
extern void _cleanup();
}
extern void __dtors();

static void cleanup() {
        __dtors();
        _cleanup();
}

extern void _main()
{
        typedef void (*PFV)();
        extern PFV _ctors[];
	atexit(cleanup);
        for (PFV* pf=_ctors; *pf; pf++) {
                (**pf)();
                *pf = 0; // permits main to be called recursively
        }
}
