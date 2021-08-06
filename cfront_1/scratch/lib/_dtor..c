#line 1 "../../lib/static/_dtor.c"

/* <<cfront 1.2.1 2/16/87>> */
/* < ../../lib/static/_dtor.c */
char *_new(); char _delete(); char *_vec_new(); char _vec_delete();

#line 1 "../../lib/static/_dtor.c"

#line 2 "../../lib/static/_dtor.c"
typedef char (*PFV )();
extern PFV _dtors [1];
PFV _dtors [1]= { 0 } ;

/* the end */
