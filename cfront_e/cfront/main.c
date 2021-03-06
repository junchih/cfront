// 1985 Feb 08 12:48
/* %Z% %M% %I% %H% %T% */
/***********************************************************************

	C++ source for cfront, the C++ compiler front-end
	written in the computer science research center of Bell Labs

	Copyright (c) 1984 AT&T Technologies, Inc. All rigths Reserved
	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T TECHNOLOGIES, INC.

	If you ignore this notice the ghost of Ma Bell will haunt you forever.

main.c:

	Initialize global environment
	Read argument line
	Start compilation
	Clean up end exit

**************************************************************************/

/*#include <signal.h>
*/

#include <time.h>
char* ctime(long*);
long time(long*);
long start_time, stop_time;

#include "cfront.h"

char* prog_name = "<<cfront (release E) 1/30/85>>";

extern char* src_file_name;
char* src_file_name = 0;

bit Styp = 1;
bit Ssimpl = 1;

bit old_fct_accepted = 1;
TOK scope_default = STATIC;
bit fct_void;
bit st_init;

char* line_format = "\n# %d \"%s\"\n";

Plist isf_list;
Pstmt st_ilist;
Pstmt st_dlist;

int Nspy;
int Nfile = 1 , Nline, Ntoken;
int Nfree_store, Nalloc, Nfree;
int Nname;
int Nn, Nbt, Nt, Ne, Ns, Nc, Nstr, Nl;
extern int NFn, NFtn, NFbt, NFpv, NFf, NFe, NFs, NFc, NFl;

simpl_init();
typ_init();
syn_init();
lex_init();
error_init();
print_free();
read_align(char*);
print_align(char*);

void spy(char* s)
{
	if (s) fprintf(stderr,"%s:\n",s);
	fprintf(stderr,"files=%d lines=%d tokens=%d\n",Nfile, Nline, Ntoken);
	fprintf(stderr,"Names: distinct=%d global=%d type=%d\n",
		Nname, gtbl->max(), ktbl->max());
	fflush(stderr);
	if (start_time && stop_time) {
		fprintf(stderr,"start time: %s", ctime(&start_time) );
		fprintf(stderr,"stop time:  %s", ctime(&stop_time) );
		fprintf(stderr,"real time delay %ld: %d lines per second\n",
			stop_time-start_time, Nline/(stop_time-start_time) );
		fflush(stderr);
	}
	fprintf(stderr,"free store=%dbytes alloc()=%d free()=%d ",
		Nfree_store, Nalloc, Nfree);
	print_free();
	fflush(stderr);
	fprintf(stderr,"sizeof: n=%d bt=%d f=%d p=%d v=%d e=%d c=%d l=%d\n",
		sizeof(name), sizeof(basetype), sizeof(fct),
		sizeof(ptr), sizeof(vec),
		sizeof(expr), sizeof(typed_obj), /*sizeof(elist)*/16 );
	fprintf(stderr,"alloc(): n=%d bt=%d t=%d e=%d s=%d c=%d str=%d l=%d\n",
		Nn, Nbt, Nt, Ne, Ns, Nc, Nstr,Nl);
	fprintf(stderr,"free(): n=%d bt=%d t=%d e=%d s=%d c=%d str=? l=%d\n",
		NFn, NFbt, NFpv+NFf, NFe, NFs, NFc, NFl);
	fflush(stderr);
	fprintf(stderr,"%d errors\n",error_count);
	fflush(stderr);
}

Pname dcl_list;	/* declarations generated while declaring something else */

char *st_name( int ); /* generates names of static ctor, dtor callers */

void run()
/*
	run the appropriate stages
*/
{
	Pname n;
	int i = 1;

	while (n=syn()) {
		Pname nn;
 		Pname nx;

		if (n == (Pname)1) continue;

		if (Styp == 0) {
			n->dcl_print(SM);
			lex_clear();
			continue;
		}

		for (nn=n; nn; nn=nx) {
			nx = nn->n_list;
			nn->n_list = 0;
			if (nn->dcl(gtbl,EXTERN) == 0) continue;

			if (error_count) continue;

			if (Ssimpl) nn->simpl();

			/* handle generated declarations */
			for (Pname dx, d=dcl_list; d; d=dx) {
				dx = d->n_list;
				d->dcl_print(0);
				delete d;
			}
			dcl_list = 0;

			if (nn->base) nn->dcl_print(0);

			switch (nn->tp->base) {	/* clean up */
			default:
			{	Pexpr i = nn->n_initializer;
				if (i && i!=(Pexpr)1) DEL(i);							break; //(#) Clipped at "DEL(i);				".
			}

			case FCT:
			{	Pfct f = (Pfct)nn->tp;
				if (f->body && (debug || f->f_inline==0)) {
					DEL(f->body);
				/*	f->body = 0;  leave to detect re-definition, but do not use it */ //(#) Clipped at "re-definition".
				}
				break;
			}

			case CLASS:
			{	Pclass cl = (Pclass)nn->tp;
				register Pname p;
				for (p=cl->pubmem; p; p=p->n_list) {
					switch (p->tp->base) {
					case FCT:
					{	Pfct f = (Pfct)p->tp;
						if (f->body && (debug || f->f_inline==0)) { //(#) Clipped at "f->f_inlin".
							DEL(f->body);
							f->body = 0;
						}
					}
					case CLASS:
					case ENUM:
						break;
					case COBJ:
					case EOBJ:
						DEL(p);
						break;
					default:
						delete p;
					}
				}
				cl->pubmem = 0;

				
				for (p=cl->privmem; p; p=p->n_list) {
					switch (p->tp->base) {
					case FCT:
					{	Pfct f = (Pfct)p->tp;
						if (f->body && (debug || f->f_inline==0)) { //(#) Clipped at "f->f_inlin".
							DEL(f->body);
							f->body = 0;
						}
					}
					case CLASS:
					case ENUM:
						break;
					case COBJ:
					case EOBJ:
						DEL(p);
						break;
					default:
						delete p;
					}
				}
				cl->privmem = 0;
				cl->permanent = 3;
				break;
			}
			}

			DEL(nn);
		}

		lex_clear();
	}

	switch (no_of_undcl) {
	case 0:
		break;
	case 1:
		error('w',"undeclaredF%n called",undcl1);
		break;
	case 2:
		error('w',"%d undeclaredFs called:%n and%n",no_of_undcl,undcl1,undcl2); //(#) Clipped at "undcl1,undc".
		break;
	default:
		error('w',"%d undeclaredFs called,%n,%n etc",no_of_undcl,undcl1,undcl2); //(#) Clipped at "undcl1,und".
	}

	Pname m;
	if (fct_void == 0)
	for (m=gtbl->get_mem(i=1); m; m=gtbl->get_mem(++i)) {
/*error('d',"global:%k n_key%k perm %d %n", m->base, m->n_key, m->permanent, m );*/
		if (m->base==TNAME
		|| m->n_scope==EXTERN
		|| m->n_stclass == ENUM) continue;

		Ptype t = m->tp;
		if (t == 0) continue;
	ll:
		switch (t->base) {
		case TYPE:	t=((Pbase)t)->b_name->tp; goto ll;
		case CLASS:
		case ENUM:
		case COBJ:
		case OVERLOAD:
		case VEC:	continue;
		case FCT:	if ( ((Pfct)t)->f_inline ) continue;

		}

		if (m->n_addr_taken==0 && m->n_used==0) {
			Cdcl = m;
			if (m->tp->tconst() ==0)
				error('w',"static%n declared but not used",m);
		}
	}

	if (st_ilist) {	/*	make an "init" function;
				it calls all constructors for static objects
			*/
		Pname n = new name( st_name('I') );
		Pfct f = new fct(void_type,0,1);
		n->tp = f;
		f->body = new block(st_ilist->where,0,0);
		n->n_sto = EXTERN;
		(void) n->dcl(gtbl,EXTERN);
		n->simpl();
		f->body->s = st_ilist;
		f->simpl();
		n->dcl_print(0);
	}

	if (st_dlist) {	/*	make a "done" function;
				it calls all destructors for static objects
			*/
		Pname n = new name( st_name('D') );
		Pfct f = new fct(void_type,0,1);
		n->tp = f;
		f->body = new block(st_dlist->where,0,0);
		n->n_sto = EXTERN;
		(void) n->dcl(gtbl,EXTERN);
		n->simpl();
		f->body->s = st_dlist;
		f->simpl();
		n->dcl_print(0);
	}

	if (debug==0) {	/* print inline function definitions */
		Plist l;
		for (l=isf_list; l; l=l->l) {
			Pname n = l->f;
			Pfct f = (Pfct)n->tp;

			switch (f->base) {
			case FCT: break;
			default: error('i',"inline list corrupted\n");
			case OVERLOAD:
				n = ((Pgen)f)->fct_list->f;	/* first fct */
				f = (Pfct)n->tp;
			}

/*fprintf(stderr,"%s() tp (%d %d) %d %d\n", n->string, n->tp, n->tp?n->tp->base:0, n->n_addr_taken, f->f_virtual); fflush(stderr);*/ //(#) Clipped at "base:0, n".
			if (n->n_addr_taken || f->f_virtual) {
/*				if (st_init) putst("asm(\"library\");");*/
				n->tp->dcl_print(n);
			}
		}
	}

	fprintf(out_file,"\n/* the end */\n");

}

bit warn = 1;	/* printout warning messages */
bit debug = 0;	/* code generation for debugger */
char* afile = "default";

int no_of_undcl;
Pname undcl1, undcl2;

main(int argc, char* argv[])
/*
	read options, initialize, and run
*/
{
	extern char* mktemp();
	register char * cp;
	short i;

	/*(void) signal(SIGINT,&sig_exit);
	(void) signal(SIGTERM,sig_exit);
	(void) signal(SIGQUIT,sig_exit);
*/


	error_init();

	for (i=1; i<argc; ++i) {
		switch (*(cp=argv[i])) {
		case '+':
			while (*++cp) {
				switch(*cp) {
				case 't':
					fprintf(stderr,"type check only\n");
					Ssimpl = 0;
					break;
				case 's':
					fprintf(stderr,"syntax check only\n");
					Styp = Ssimpl = 0;
					break;
				case 'w':
					warn = 0;
					break;
				case 'd':
					debug = 1;
					break;
				case 'f':
					src_file_name = cp+1;
					goto xx;
				case 'x':	/* read in table for cross compilation */ //(#) Clipped at "cross compilat".
					if (read_align(afile = cp+1)) {
						fprintf(stderr,"bad size-table (option +x)"); //(#) Clipped at "(opt".
						exit(11);
					}
					goto xx;
				case 'C':	/* preserve comments */
					error('s',"cannot preserve comments");
					break;
				case 'V':	/* C with classes compatability */
					fct_void = 1;
					/* no break */
				case 'E':
					scope_default = EXTERN;
					break;
				case 'S':
					Nspy++;
					break;
				case 'L':
					line_format = "\n#line %d \"%s\"\n";
					break;
				case 'I':
					st_init = 1;
					break;
				default:
					fprintf(stderr,"%s: unexpected option: -%c ignored\n",prog_name,*cp); //(#) Clipped at "option: -%c ".

					break;
				}
			}
		xx:
			break;
		default:
			fprintf(stderr,"%s: bad argument \"%s\"\n",prog_name,cp);
			exit(11);
		}
	}


	fprintf(out_file,"\n/* %s */\n",prog_name);
	if (src_file_name) fprintf(out_file,"/* < %s */\n",src_file_name);

	if (Nspy) {
		start_time = time(0);
		print_align(afile);
	}
	fflush(stderr);
	if (Ssimpl) print_mode = SIMPL;
	otbl_init();
	lex_init();
	syn_init();
	typ_init();
	simpl_init();
	scan_started = 1;
	curloc.putline();
	run();
	if (Nspy) {
		stop_time = time(0);
		spy(src_file_name);
	}

	return (0<=error_count && error_count<127) ? error_count : 127;
}

extern int strcat(char*, char*);
char * st_name( int iord ) {
	static char *name = 0;
	static char *prefix = "_ST_"; /* first character must be valid in a
					 C identifier */
	if ( iord != 'I' && iord != 'D' )
		error( 'i', "bad ST_ type %d\n", iord );
	if ( !name ) {
		int stilen = strlen( prefix ) + 1 +
			( src_file_name ) ? strlen( src_file_name ) : 0;
		name = new char[ stilen ];
		strcpy( name, prefix );
		if ( src_file_name ) strcat( name, src_file_name );
		char *p = name;
		while ( *++p ) {
			if ( 'a' <= *p && *p <= 'z' ||
			'A' <= *p && *p <= 'Z' ||
			'0' <= *p && *p <= '9' ) continue;
			*p = '_';
		}
	}
	name[ strlen( prefix ) - 1 ] = iord;
	return name;
}
