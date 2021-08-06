#line 1 "../../lib/static/exit.c"

/* <<cfront 1.2.1 2/16/87>> */
/* < ../../lib/static/exit.c */
char *_new(); char _delete(); char *_vec_new(); char _vec_delete();

#line 1 "../../lib/static/exit.c"

#line 3 "../../lib/static/exit.c"
extern char _exit ();
extern char _cleanup ();
extern char dtors ();

#line 7 "../../lib/static/exit.c"
extern char exit (_au0_i )int _au0_i ;
{ 
#line 9 "../../lib/static/exit.c"
dtors ( ) ;
_cleanup ( ) ;
_exit ( _au0_i ) ;
}
;

/* the end */
