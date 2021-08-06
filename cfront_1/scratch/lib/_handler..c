#line 1 "../../lib/new/_handler.c"

/* <<cfront 1.2.1 2/16/87>> */
/* < ../../lib/new/_handler.c */
char *_new(); char _delete(); char *_vec_new(); char _vec_delete();

#line 1 "../../lib/new/_handler.c"

#line 3 "../../lib/new/_handler.c"
typedef char (*PFVV )();

#line 5 "../../lib/new/_handler.c"
extern PFVV _new_handler ;
PFVV _new_handler = 0 ;
extern PFVV set_new_handler (_au0_handler )PFVV _au0_handler ;
{ 
#line 9 "../../lib/new/_handler.c"
PFVV _au1_rr ;

#line 9 "../../lib/new/_handler.c"
_au1_rr = _new_handler ;
_new_handler = _au0_handler ;
return _au1_rr ;
}
;

/* the end */
