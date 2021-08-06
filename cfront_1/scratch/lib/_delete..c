#line 1 "../../lib/new/_delete.c"

/* <<cfront 1.2.1 2/16/87>> */
/* < ../../lib/new/_delete.c */
char *_new(); char _delete(); char *_vec_new(); char _vec_delete();

#line 1 "../../lib/new/_delete.c"

#line 2 "../../lib/new/_delete.c"
extern int free ();
char _delete (_au0_p )char *_au0_p ;
{ 
#line 5 "../../lib/new/_delete.c"
if (_au0_p )free ( ((char *)_au0_p )) ;
}
;

/* the end */
