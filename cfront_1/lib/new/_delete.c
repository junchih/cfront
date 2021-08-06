/*ident	"@(#)cfront:lib/new/_delete.c	1.3" */
extern free(char*);
extern void operator delete(void* p)
{
	if (p) free( (char*)p );
}
