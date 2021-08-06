// 1985 Feb 08 12:48
/* @(#) norm.c 1.1 1/2/85 17:58:42 */
/************************************************************************

	C++ source for cfront, the C++ compiler front-end
	written in the computer science research center of Bell Labs

	Copyright (c) 1984 AT&T Technologies, Inc. All rigths Reserved
	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T TECHNOLOGIES, INC.

	If you ignore this notice the ghost of Ma Bell will haunt you forever.

norm.c:

	"normalization" handles problems which could have been handled
	by the syntax analyser; but has not been done. The idea is
	to simplify the grammar and the actions associated with it,
	and to get a more robust error handling

****************************************************************************/

#include "cfront.h"
#include "size.h"

extern void syn_init();
void syn_init()
{
	any_type = new basetype(ANY,0);
	PERM(any_type);
	dummy = new expr(DUMMY,0,0);
	PERM(dummy);
	dummy->tp = any_type;
	zero = new expr(ZERO,0,0);
	PERM(zero);
}


char* make_name(TOK c)
{
	static stcount;

	char* s = new char[8];	/* as it happens: fits in two words */


	if (99999 <= ++stcount) error('i',"too many generated names");

	s[0] = '_';
	s[1] = c;
	int count = stcount;
	int i = 2;
	if (10000 <= count) {
		s[i++] = '0' + count/10000;
		count %= 10000;
	}
	if (1000 <= count) {
		s[i++] = '0' + count/1000;
		count %= 1000;
	}
	else if (2<i) s[i++] = '0';

	if (100 <= count) {
		s[i++] = '0' + count/100;
		count %= 100;
	}
	else if (2<i) s[i++] = '0';

	if (10 <= count) {
		s[i++] = '0' + count/10;
		count %= 10;
	}
	else if (2<i) s[i++] = '0';

	s[i++] = '0' + count;
	s[i] = 0;

	return s;
}

Pbase basetype.type_adj(TOK t)
{
	switch (base) {
	case COBJ:
	case EOBJ:
	{	Pbase bt = new basetype(0,0);
		*bt = *this;
		DEL(this);
		this = bt;
	}
	}
			
	if (b_xname) {
		if (base)
			error("badBT:%n%k",b_xname,t);
		else {
			base = TYPE;
			b_name = b_xname;
		}
		b_xname = 0;
	}

	switch (t) {
	case TYPEDEF:	b_typedef = 1;	break;
	case INLINE:	b_inline = 1;	break;
	case VIRTUAL:	b_virtual = 1;	break;
	case CONST:	b_const = 1;	break;
	case UNSIGNED:	b_unsigned = 1;	break;
	case SHORT:	b_short = 1;	break;
	case LONG:	b_long = 1;	break;
	case FRIEND:
	case OVERLOAD:
	case EXTERN:
	case STATIC:
	case AUTO:
	case REGISTER:
		if (b_sto)
			error("badBT:%k%k",b_sto,t);
		else
			b_sto = t;
		break;
	case VOID:
	case CHAR:
	case INT:
	case FLOAT:
	case DOUBLE:
		if (base)
			error("badBT:%k%k",base,t);
		else
			base = t; 
		break;
	default:
		error('i',"basetype.type_adj(%k)",t);
	}
	return this;
}

Pbase basetype.name_adj(Pname n)
{
	if (b_xname) {
		if (base)
			error("badBT:%n%n",b_xname,n);
		else {
			base = TYPE;
			b_name = b_xname;
		}
		b_xname = 0;
	}
	b_xname = n;
	return this;
}

Pbase basetype.base_adj(Pbase b)
{
	Pname bn = b->b_name;

	switch (base) {
	case COBJ:
	case EOBJ:
		error("NX after%k%n",base,b_name);
		return this;
	}

	if (base) {
		if (b_name)
			error("badBT:%k%n%k%n",base,b_name,b->base,bn);
		else
			error("badBT:%k%k%n",base,b->base,bn);
	}
	else {
		base = b->base;
		b_name = bn;
		b_table = b->b_table;
	}
	return this;
}

Pbase basetype.check(Pname n)
/*
	"n" is the first name to be declared using "this"
	check the consistency of "this"
	and use "b_xname" for "n->string" if possible and needed
*/
{
	b_inline = 0;
	b_virtual = 0;
/*fprintf(stderr,"check n: %d %s b: %d %d %s\n",n,(n)?n->string:"",this,base,(b_name)?b_name->string:"");fflush(stderr);*/ //(#) Clipped at "(b_name".
	if (b_xname && (n->tp || n->string)) {
		if (base)
			error("badBT:%k%n",base,b_xname);
		else {
			base = TYPE;
			b_name = b_xname;
		}
		b_xname = 0;
	}

	if (b_xname) {
		if (n->string)
			error("twoNs inD:%n%n",b_xname,n);
		else {
			n->string = b_xname->string;
			b_xname->hide();
		}
		b_xname = 0;
	}

	switch (base) {
	case 0:
		base = INT;
		break;
	case EOBJ:
	case COBJ:
		if (b_name->base == TNAME)
			error('i',"TN%n inCO %d",b_name,this);
	}

	if (b_long || b_short) {
		TOK sl = (b_short) ? SHORT : LONG;
		if (b_long && b_short) error("badBT:long short%k%n",base,n);
		if (base != INT)
			error("badBT:%k%k%n",sl,base,n);
		else
			base = sl;
		b_short = b_long = 0;
	}

	if (b_typedef && b_sto) error("badBT:typedef%k%n",b_sto,n);
	b_typedef = b_sto = 0;

	if (Pfctvec_type == 0) return this;

	if (b_const) {
		return this;
/*
		switch (base) {
		case INT:
			;
		}
*/
	}
	else if (b_unsigned) {
		switch (base) {
		case LONG:
		/*	error('s',"unsigned long");*/
			delete this;
			return ulong_type;
		case SHORT:
			delete this;
			return ushort_type;
		case INT:
			delete this;
			return uint_type;
		case CHAR:
			delete this;
			return uchar_type;
		default:
			error("badBT: unsigned%k%n",base,n);
			b_unsigned = 0;
			return this;
		}
	}
	else {
		switch (base) {
		case LONG:
			delete this;
			return long_type;
		case SHORT:
			delete this;
			return short_type;
		case INT:
			if (this != int_type) delete this;
			return int_type;
		case CHAR:
			delete this;
			return char_type;
		case VOID:
			delete this;
			return void_type;
		case TYPE:
			/* use a single base saved in the keyword */
/*fprintf(stderr,"type %d bn %d %s q %d\n",this,b_name,b_name->string,b_name->n_qualifier);*/ //(#) Clipped at "n_qual".
			if (b_name->n_qualifier) {
				delete this;
				return (Pbase)b_name->n_qualifier;
			}
			else {
				PERM(this);
				b_name->n_qualifier = (Pname)this;
				return this;
			}
		default:
			return this;
		}
	}
}

Pname basetype.aggr()
/*
	"type SM" seen e.g.	struct s {};
				class x;
				enum e;
				int tname;
				friend cname;
				friend class x;
				int;

	convert
		union { ... };
	into
		union name { ... } name ;
*/
{
	Pname n;

	if (b_xname) {
		if (base) {
			Pname n = new name(b_xname->string);
			b_xname->hide();
			b_xname = 0;
			return n->normalize(this,0,0);
		}
		else {
			base = TYPE;
			b_name = b_xname;
			b_xname = 0;
		}
	}


	switch (base) {
	case COBJ:
	{	Pclass cl = (Pclass)b_name->tp;
		char* s = cl->string;
/*fprintf(stderr,"COBJ (%d %s) -> (%d %d) ->(%d %d)\n",this,b_name->string,b_name,b_name->base,cl,cl->base);*/ //(#) Clipped at "b_name,b_".
		if (b_name->base == TNAME) error('i',"TN%n inCO",b_name);
		if (b_const) error("const%k%n",cl->csu,b_name);

		if (cl->c_body == 2) {	/* body seen */
			if (s[0]=='_' && s[1]=='C') {
				char* ss = new char[5];
				Pname obj = new name(ss);
				if (cl->csu == UNION) {
					strcpy(ss,s);
					ss[1] = 'O';
					cl->csu = ANON;
					return obj->normalize(this,0,0);
				}
				error('w',"un-usable%k ignored",cl->csu);
			}
			cl->c_body = 1;
			return b_name;
		}
		else {	/* really a typedef for cfront only: class x; */
			if (b_sto == FRIEND) goto frr;
			return 0;
		}
	}

	case EOBJ:
	{	Penum en = (Penum)b_name->tp;
/*fprintf(stderr,"EOBJ (%d %s) -> (%d %d) ->(%d %d)\n",this,b_name->string,b_name,b_name->base,en,en->base);*/ //(#) Clipped at "b_name,b_".
		if (b_name->base == TNAME) error('i',"TN%n in enumO",b_name);
		if (b_const) error("const enum%n",b_name);
		if (en->e_body == 2) {
			en->e_body = 1;
			return b_name;
		}
		else {
			if (b_sto == FRIEND) goto frr;
			return 0;
		}
	}

	default:
		if (b_typedef) error('w',"illegal typedef ignored");

		if (b_sto == FRIEND) {
		frr:
			Pname fr = ktbl->look(b_name->string,0);
			if (fr == 0) error('i',"cannot find friend%n",b_name);
			n = new name(b_name->string);
			n->n_sto = FRIEND;
			n->tp = fr->tp;
			return n;
		}
		else {
			n = new name(make_name('D'));
			n->tp = any_type;
			error('w',"NX inDL");
			return n;
		}
	}
}

void name.hide()
/*
	hide "this": that is, "this" should not be a keyword in this scope
*/
{
	if (base != TNAME) return;
	if (n_key == 0) {
/*error('d',"hide%n",this);*/
		if (lex_level == bl_level) error('w',"%n redefined",this);
		modified_tn = new name_list(this,modified_tn);
		n_key = HIDDEN;
	}
}
void set_scope(Pname tn)
/*
	enter the scope of class tn after seeing "tn.f"
*/
{
	Pbase b;
	Pclass cl;
	Plist l;
	if (tn->base != TNAME) error('i',"set_scope: not aTN %d %d",tn,tn->base);
	b = (Pbase)tn->tp;
	if (b->b_name->tp->base != CLASS) error('i',"T of%n not aC (%k)",tn,b->b_name->tp->base); //(#) Clipped at "b->b_na".
	cl = (Pclass)b->b_name->tp;
	for (l=cl->tn_list; l; l=l->l) {
		Pname n = l->f;
		n->n_key = (n->lex_level) ? 0 : HIDDEN;
		modified_tn = new name_list(n,modified_tn);
	}
}

void restore()
/*
*/
{
	Plist l;

	for (l=modified_tn; l; l=l->l) {
		Pname n = l->f;
		if (n->lex_level <= bl_level) {
			n->n_key = 0;
		}
		else {
			n->n_key = HIDDEN;
		}
	}
}

Pbase start_cl(TOK t, Pname c, Pname b)
{
	if (c == 0) c = new name(make_name('C'));
	Pname n = c->tname(t);			/* t ignored */
	n->where = curloc;
	Pbase bt = (Pbase)n->tp;		/* COBJ */
	if (bt->base != COBJ) {
		error("twoDs of%n:%t andC",n,bt);
		exit(88);
	}
	Pclass occl = ccl;
	ccl = (Pclass)bt->b_name->tp;		/* CLASS */
	ccl->in_class = occl;
	ccl->tn_list = modified_tn;
	modified_tn = 0;
	ccl->string = n->string;
	ccl->csu = t;				/* ! */
	if (b) ccl->clbase = b->tname(t);
	return bt;	
}

void end_cl()
{
	Pclass occl = ccl->in_class;
	Plist ol = ccl->tn_list;
	ccl->c_body = 2;
	ccl->tn_list = modified_tn;
	if (modified_tn) restore();
	modified_tn = ol;
	ccl = occl;
}

Pbase end_enum(Pname n, Pname b)
{
	if (n == 0) n = new name(make_name('E'));
	n = n->tname(ENUM);
	Pbase bt = (Pbase)n->tp;
	if (bt->base != EOBJ) {
		error("twoDs of%n:%t and enum",n,bt);
		exit(88);
	}
	Penum en = (Penum)bt->b_name->tp;
	en->e_body = 2;
	en->mem = name_unlist((class nlist *)b);
	if (en->defined) error("enum%n defined twice",n);
	return bt;
}

Pname name.tdef()
/*
	typedef "this"
*/
{
	Pname n = ktbl->insert(this,0);
	if (tp == 0) error('i',"typedef%n tp==0",this);
	n->base = base = TNAME;
	PERM(n);
	PERM(tp);
	modified_tn = new name_list(n,modified_tn);
	return n;
}

Pname name.tname(TOK csu)
/*
	"csu" "this" seen, return typedef'd name for "this"
	return	(TNAME,x)
	x:	(COBJ,y)
	y:	(NAME,z)
	z:	(CLASS,ae);
*/
{
	switch (base) {
	case TNAME:
		return this;
	case NAME:
	{	Pname tn = ktbl->insert(this,0);
		Pname on = new name;
		tn->base = TNAME;
		modified_tn = new name_list(tn,modified_tn);
		tn->n_list = n_list = 0;
		string = tn->string;
		*on = *this;
		switch (csu) {
		case ENUM:
			tn->tp = new basetype(EOBJ,on);
			on->tp = new enumdef(0);
			break;
		default:
			on->tp =  new classdef(csu,0);
			((Pclass)on->tp)->string = tn->string;
			tn->tp = new basetype(COBJ,on);
			((Pbase)tn->tp)->b_table = ((Pclass)on->tp)->memtbl;
		}
		PERM(tn);
		PERM(tn->tp);
		PERM(on);
		PERM(on->tp);
/*fprintf(stderr,"tname %s -> n (%d %d) n->tp (%d %d)\n",string,tn,tn->base,tn->tp,tn->tp->base); fflush(stderr);*/ //(#) Clipped at "tn->tp,t".
		return tn;
	}
	default:
		error('i',"tname(%s %d %k)",string,this,base);
	} 
}


Pname name.normalize(Pbase b, Pblock bl, bit cast)
/*
	if (bl) : a function definition (check that it really is a type

	if (cast) : no name string

	for each name on the name list
	invert the declarator list(s) and attatch basetype
	watch out for class object initializers

	convert
		struct s { int a; } a;
	into
		struct s { int a; }; struct s a;
*/
{
	Pname n;
	Pname nn;
	TOK stc = b->b_sto;
	bit tpdf = b->b_typedef;
	bit inli = b->b_inline;
	bit virt = b->b_virtual;
	Pfct f;
	Pname nx;

	if (b == 0) error('i',"%d->N.normalize(0)",this);
	if (this == 0) error('i',"0->N.normalize(%k)",base);

	if (inli && stc==EXTERN)  {
		error("both extern and inline");
		inli = 0;
	}
/*fprintf(stderr,"name.norm(%d %s) tp (%d %d)\n",this,string,tp,tp->base);*/

	if (stc==FRIEND && tp==0) {
			/*	friend x;
				must be handled during syntax analysis to cope with
					class x { friend y; y* p; };
				"y" is not local to "x":
					class x { friend y; ... }; y* p;
				is legal
			*/
		if (b->base) error(0,"T specified for friend");
		if (n_list) {
			error("L of friends");
			n_list = 0;
		}
		Pname nx = tname(CLASS);
		modified_tn = modified_tn->l;	/* global */
		n_sto = FRIEND;
		tp = nx->tp;
		return this;
	}

	if (cast) string = "";
	b = b->check(this);

	switch (b->base) {	/*	separate class definitions
					from object and function type declarations
				*/
	case COBJ:
		nn = b->b_name;
/*fprintf(stderr,"COBJ (%d %s) -> (%d %d body=%d)\n",nn,nn->string,nn->tp,nn->tp->base,((Pclass)nn->tp)->c_body);*/ //(#) Clipped at "nn->tp->ba".
		if (((Pclass)nn->tp)->c_body==2) {	/* first occurrence */
			if (tp && tp->base==FCT) {
				error('s',"C%n defined as returnT for%n (did you forget a ';' after '}' ?)",((Pclass)nn->tp)->csu,nn,this); //(#) Clipped at "(did you fo".
				nn = this;
				break;
			}
			nn->n_list = this;
			((Pclass)nn->tp)->c_body = 1;	/* other occurences */
		}
		else
			nn = this;
		break;
	case EOBJ:
		nn = b->b_name;
		if (((Penum)nn->tp)->e_body==2) {
			if (tp && tp->base==FCT) {
				error('s',"enum%n defined as returnT for%n (did you forget a ';'?)",nn,this); //(#) Clipped at "(did you".
				nn = this;
				break;
			}
			nn->n_list = this;
			((Penum)nn->tp)->e_body = 1;
		}
		else
			nn = this;
		break;
	default:
		nn = this;
	}

	for (n=this; n; n=nx) {
		Ptype t = n->tp;
		nx = n->n_list;
		n->n_sto = stc;

		if (t
		&& n_oper==TNAME
		&& t->base==FCT) {	/* HORRIBLE FUDGE: fix the bad grammar */
			Pfct f = (Pfct)t;
			Pfct f2 = (Pfct)f->returns;
			if (f2 && f2->base==FCT) {
				Pexpr e = f2->argtype;
/*error('d',"%s: mis-analyzedP toF",n->string);*/
				if  (e->base == ELIST) {
					/*	get the real name,
						fix its type
					*/
					if (e->e2 || e->e1->base!=DEREF) goto zse;
					Pname rn = (Pname)e->e1->e1;
					if (rn->base!=NAME) goto zse;
/*error('d',"realN %n b==%t",rn,b);*/
					f->returns = new ptr(PTR,0);
					b = new basetype(TYPE,ktbl->look(n->string,0)); //(#) Clipped at "n->string,".
					n->n_oper = 0;
					n->string = rn->string;
					n->base = NAME;
				}
			}
		}
zse:
		if (n->base == TNAME) error('i',"redefinition ofTN%n",n);

		if (t == 0) {
			if (bl == 0)
				n->tp = t = b;
			else {
				error("body of nonF%n",n);
				t = new fct(defa_type,0,0);
			}
		}

		switch (t->base) {
		case PTR:
		case RPTR:
			n->tp = ((Pptr)t)->normalize(b);
			break;
		case VEC:
			n->tp = ((Pvec)t)->normalize(b);
			break;
		case FCT:
			n->tp = ((Pfct)t)->normalize(b);
			break;
		case FIELD:
			if (n->string == 0) n->string = make_name('F');
			n->tp = t;
			Pbase tb = b;
		flatten:
			switch (tb->base) {
			case TYPE:   /* chase typedefs */
				tb = (Pbase)tb->b_name->tp;
				goto flatten;
			case INT:
				((Pbase)t)->b_unsigned = b->b_unsigned;
				((Pbase)t)->b_const = b->b_const;
				break;
			default:
				error("non-int field");
				n->tp = defa_type;
			}
			break;
		}

		f = (Pfct) n->tp;

		if (f->base != FCT) {
			if (bl) {
				error("body for nonF%n",n);
				n->tp = f = new fct(defa_type,0,0);
				continue;
			}
			if (inli) error("inline nonF %n",n);
			if (virt) error("virtual nonF %n",n);
				
			if (tpdf) {
				if (n->n_initializer) {
					error("Ir for typedefN%n",n);
					n->n_initializer = 0;
				}
				n->tdef();
			}
			continue;
		}

		f->f_inline = inli;
		f->f_virtual = virt;	

		if (tpdf) error("typedef%n",n);
		
		if (f->body = bl) continue;

		/*
			Check function declarations.
			Look for class object instansiations
			The real ambiguity:		; class x fo();
				is interpreted as an extern function
				declaration NOT a class object with an
				empty initializer
		*/
		{	Pname cn = f->returns->is_cl_obj();
			bit clob = (cn || cl_obj_vec);
/*error('d',"%n: fr%t cn%n",n,f->returns,cn);*/
			if (f->argtype) { /* check argument/initializer list */
				Pname nn;

				for (nn=f->argtype; nn; nn=nn->n_list) {
					if (nn->base != NAME) {
						if (!clob) {
							error("ATX for%n",n);
							goto zzz;
						}
						goto is_obj;
					}
/*
					if (nn->string) {
						error("AN%n inD of%n",nn,n);
						nn->string = 0;
					}
*/
					if (nn->tp) goto ok;
				}
				if (!clob) {
					error("FALX");
					goto zzz;
				}
		is_obj:
/*fprintf(stderr,"is_obj: %d %s tp = %d %d\n",this,string,f->returns,f->returns->base); fflush(stderr);*/ //(#) Clipped at "f->returns->bas".
				/* it was an initializer: expand to constructor */
				n->tp = f->returns;
				if (f->argtype->base != ELIST) f->argtype = (Pname)new expr(ELIST,(Pexpr)f->argtype,0); //(#) Clipped at "f->argtype = (Pname)".
				n->n_initializer = new texpr(VALUE,cn->tp,(Pexpr)f->argtype); //(#) Clipped at "(Pexpr)f-".
				goto ok;
			zzz:
				if (f->argtype) {
					DEL(f->argtype);
					f->argtype = 0;
					f->nargs = 0;
					f->nargs_known = !fct_void;
				}
			}
			else {	/* T a(); => function declaration */
/*
				if (clob) {
					DEL(n->tp);
					n->tp = f->returns;
				}
*/
			}
		ok:
			;
		}
	}
	return nn;
}

Ptype vec.normalize(Ptype vecof)
/*
*/
{
	Ptype t = typ;
	if (this == 0) error('i',"0->vec.normalize()");
	typ = vecof;

	if (t == 0) return this;

xx:
	switch (t->base) {
	case TYPE:	t = ((Pbase)t)->b_name->tp;	goto xx;
	case PTR:
	case RPTR:	return ((Pptr)t)->normalize(this);
	case VEC:	return ((Pvec)t)->normalize(this);
	case FCT:	return ((Pfct)t)->normalize(this);
	default:	error('i',"bad vectorT(%d)",t->base);
	}
}

Ptype ptr.normalize(Ptype ptrto)
{
	Ptype t = typ;
	if (this == 0) error('i',"0->ptr.normalize()");
	typ = ptrto;

	if (t == 0) {
		Pbase b = (Pbase) ptrto;
		if (Pfctvec_type
		&& rdo==0
		&& b->b_unsigned==0
		&& b->b_const==0
		&& base==PTR) {
			switch (b->base) {
			case INT:
				delete this;
				return Pint_type;
			case CHAR:
				delete this;
				return Pchar_type;
			case VOID:
				delete this;
				return Pvoid_type;
			case TYPE:
				break;
			}
		}
		if (base==RPTR && b->base==VOID) error("void& is not a validT");
		return this;
	}

xx:
	switch (t->base) {
	case TYPE:	t = ((Pbase)t)->b_name->tp; goto xx;
	case PTR:
	case RPTR:	return ((Pptr)t)->normalize(this);
	case VEC:	return ((Pvec)t)->normalize(this);
	case FCT:	return ((Pfct)t)->normalize(this);
	default:	error('i',"badPT(%d)",t->base);
	}
}

Ptype fct.normalize(Ptype ret)
/*
	normalize return type
*/
{
	register Ptype t = returns;

	if (this==0 || ret==0) error('i',"%d->fct.normalize(%d)",this,ret);

	returns = ret;
	if (t == 0) return this;

	if (argtype) {
		if (argtype->base != NAME) {
			error('i',"syntax: ANX");
			argtype = 0;
			nargs = 0;
			nargs_known = 0;
		}
/*
		else {
			Pname n;
			for (n=argtype; n; n=n->n_list) {
				if (n->string) {
					error("N inATL");
					n->string = 0;
				}
			}
		}
*/
		
	}

xx:
	switch (t->base) {
	case PTR:
	case RPTR:	return ((Pptr)t)->normalize(this);
	case VEC:	return ((Pvec)t)->normalize(this);
	case FCT:	return ((Pfct)t)->normalize(this);
	case TYPE:	t = ((Pbase)t)->b_name->tp;	goto xx;
	default:	error('i',"badFT:%k",t->base);
	}

}

	
void fct.argdcl(Pname dcl)
/*
	sort out the argument types for old syntax:
			f(a,b) int a; char b; { ... }
	beware of
			f(a) struct s { int a; }; struct s a;
*/
{
	Pname n;
/*fprintf(stderr,"%d argtype %d %d dcl %d %d\n",this, argtype, argtype?argtype->base:0, dcl, dcl?dcl->base:0); fflush(stderr);*/ //(#) Clipped at "argtype?argtype->base".
	switch (base) {
	case FCT:	break;
	case ANY:	return;
	default:	error('i',"argdcl(%d)",base);
	}

	if (argtype) {
		switch (argtype->base) {
		case NAME:
			if (dcl) error("badF definition syntax");
			for (n=argtype; n; n=n->n_list) {
				if (n->string == 0) {
				/*	error('w',"AN missing inF definition");*/
					n->string = make_name('A');
				}
			}
			return;
		case ELIST:	/* expression list:	f(a ...) */
		{	Pexpr e;
			Pname nn;
			Pname tail = 0;
			n = 0;
			if (old_fct_accepted == 0) error("old styleF definition");
			for (e=(Pexpr)argtype; e; e=e->e2) {
				/* scan the elist and build a NAME list */
				Pexpr id = e->e1;
				if (id->base != NAME) {
					error("NX inAL");
					argtype = 0;
					dcl = 0;
					goto xxx;
				}
				nn = new name(id->string);
				if (n)
					tail = tail->n_list = nn;
				else
					tail = n = nn;
			}
		xxx:
			argtype = n;
			break;
		}
		default:
			error("ALX(%d)",argtype->base);
			argtype = 0;
			dcl = 0;
		}
	}
	else {
		nargs_known = 1;
		nargs = 0;
		if (dcl) error("ADL forF withoutAs");
		return;
	}

	nargs_known = 0;

	if (dcl) {
		Pname d;
		Pname dx;
		/*	for each  argument name see if its type is specified
			in the declaration list otherwise give it the default type
		*/

		for (n=argtype; n; n=n->n_list) {
			char* s = n->string;
			if (s == 0) {
				error("AN missing inF definition");
				n->string = s = make_name('A');
			}
			else if (n->tp) error("twoTs forA %s",n->string);

			for (d=dcl; d; d=d->n_list) {
				if (strcmp(s,d->string) == 0) {
					if (d->tp->base == VOID) {
						error("voidA%n",d);
						d->tp = any_type;
					}
					n->tp = d->tp;
					n->n_sto = d->n_sto;
					d->tp = 0;	/* now merged into argtype */ //(#) Clipped at "into argtype ".
					goto xx;
				}
			}
			n->tp = defa_type;
		xx:;
			if (n->tp == 0) error('i',"noT for %s",n->string);
		}
	
		/*	now scan the declaration list for "unused declarations"
			and delete it
		*/
		for (d=dcl; d; d=dx) {
			dx = d->n_list;
			if (d->tp) {	/* not merged with argtype list */
				/*if (d->base == TNAME)  ??? */
				switch (d->tp->base) {
				case CLASS:
				case ENUM:
					/* WARNING: this will reverse the order of
					   class and enum declarations
					*/
					d->n_list = argtype;
					argtype = d;
					break;
				default:
					 error("%n inADL not inAL",d);
				}
			}
		}
	}

	/* add default argument types if necessary */
	for (n=argtype; n; n=n->n_list) {
		if (n->tp == 0) n->tp = defa_type;
		nargs++;
	}
}

Pname cl_obj_vec;	/* set if is_cl_obj() found a vector of class objects */
Pname eobj;		/* set if is_cl_obj() found an enum */

Pname type.is_cl_obj()
{
	bit v = 0;
	register Ptype t = this;

	eobj = 0;
	cl_obj_vec = 0;
xx:
	switch (t->base) {
	case TYPE:
		t = ((Pbase)t)->b_name->tp;
		goto xx;

	case COBJ:
		if (v) {
			cl_obj_vec = ((Pbase)t)->b_name;
			return 0;
		}
		else
			return ((Pbase)t)->b_name;

	case VEC:
		t = ((Pvec)t)->typ;
		v=1;
		goto xx;

	case EOBJ:
		eobj = ((Pbase)t)->b_name;
	default:	
		return 0;
	}
}
