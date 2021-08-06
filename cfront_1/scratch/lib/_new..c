#line 1 "../../lib/new/_new.c"

/* <<cfront 1.2.1 2/16/87>> */
/* < ../../lib/new/_new.c */
char *_new(); char _delete(); char *_vec_new(); char _vec_delete();

#line 1 "../../lib/new/_new.c"

#line 3 "../../lib/new/_new.c"
typedef char (*PFVV )();

#line 5 "../../lib/new/_new.c"
extern PFVV _new_handler ;

#line 7 "../../lib/new/_new.c"
char *_new (_au0_size )long _au0_size ;
{ 
#line 9 "../../lib/new/_new.c"
extern char *malloc ();
char *_au1_p ;

#line 12 "../../lib/new/_new.c"
while ((_au1_p = malloc ( ((unsigned int )_au0_size )) )== 0 ){ 
#line 13 "../../lib/new/_new.c"
if (_new_handler )
#line 14 "../../lib/new/_new.c"
(*_new_handler )( ) ;
else 
#line 16 "../../lib/new/_new.c"
return (char *)0 ;
}
return (((char *)_au1_p ));
}
;

/* the end */
