#line 1 "../../lib/static/_main.c"

/* <<cfront 1.2.1 2/16/87>> */
/* < ../../lib/static/_main.c */
char *_new(); char _delete(); char *_vec_new(); char _vec_delete();

#line 1 "../../lib/static/_main.c"

#line 2 "../../lib/static/_main.c"
extern char _main ()
#line 3 "../../lib/static/_main.c"
{ 
#line 10 "../../lib/static/_main.c"
typedef char (*PFV )();

#line 5 "../../lib/static/_main.c"
extern PFV _ctors [];
PFV *_au1_pf ;

#line 6 "../../lib/static/_main.c"
for(_au1_pf = _ctors ;*_au1_pf ;_au1_pf ++ ) { 
#line 7 "../../lib/static/_main.c"
(*(*_au1_pf ))( ) ;
(*_au1_pf )= 0 ;
}
}
;

/* the end */
