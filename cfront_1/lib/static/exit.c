/*ident	"@(#)cfront:lib/static/exit.c	1.5" */

extern void _exit(int);
extern void _cleanup();
extern void dtors();

extern void exit(int i)
{
	dtors();
	_cleanup();
	_exit(i);
}
