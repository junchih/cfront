// 1985 Feb 08 12:48
/* %Z% %M% %I% %H% %T% */
/***************************************************************************

	C++ source for cfront, the C++ compiler front-end
	written in the computer science research center of Bell Labs

	Copyright (c) 1984 AT&T Technologies, Inc. All rigths Reserved
	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T TECHNOLOGIES, INC.

	If you ignore this notice the ghost of Ma Bell will haunt you forever.

expr2.c:

	type check expressions

************************************************************************/

#include "cfront.h"
#include "size.h"

void name.assign()
{
	if (n_assigned_to++ == 0) {
		switch (n_scope) {
		case FCT:
			if (n_used && n_addr_taken==0)  {
				Ptype t = tp;
			ll:
				switch (t->base) {
				case TYPE:
					t=((Pbase)t)->b_name->tp; goto ll;
				case VEC:
					break;
				default:
					if (curr_loop)
						error('w',"%n may have been used before set",this); //(#) Clipped at "used be".
					else
						error('w',"%n used before set",this); //(#) Clipped at ",this".
				}
			}
		}
	}
}

int expr.lval(TOK oper)
{
	register Pexpr ee = this;
	register Pname n;
	int deref = 0;
	char* es;

	if (this==0 || tp==0) error('i',"%d->lval(0)",this);

	switch (oper) {
	case ADDROF:
	case G_ADDROF:
		es = "address of";
		break;
	case INCR:
	case DECR:
		es = "increment of";
		goto def;
	case DEREF:
		es = "dereference of";
		break;
	default:
		es = "assignment to";
	def:
		if (tp->tconst()) {
			if (oper) error("%s constant",es);
			return 0;
		}
	}

	forever {
		switch (ee->base) {
		default:
			if (deref==0) {
				if (oper) error("%s %k",es,ee->base);
				return 0;
			}
			return 1;
		case ZERO:
		case CCON:
		case ICON:
		case FCON:
			if (oper) error("%s numeric constant",es);
			return 0;
		case STRING:
			if (oper) error('w',"%s string constant",es);
			return 1;

		case DEREF:
		{	Pexpr ee1 = ee->e1;
			if (ee1->base == ADDROF) /* *& vanishes */
				ee = ee1->e2;
			else {
				ee = ee1;
				deref = 1;
			}
			break;
		}
		case INCR:
		case DECR:
			ee = (ee->e1) ? ee->e1 : ee->e2;
			break;

		case DOT:
			n = ee->mem;
			if (deref==0 && ee->e1->tp->tconst()) {
				if (oper) error("%sM%n of%t",es,n,ee->e1->tp);
				return 0;
			}
			goto xx;
		case REF:
			n = ee->mem;
			if (deref==0) {
				Ptype p = ee->e1->tp;
			zxc:
				switch (p->base) {
				case TYPE:	p = ((Pbase)p)->b_name->tp; goto zxc; //(#) Clipped at "goto zx".
				case PTR:	break;
				default:	error('i',"%t->%n",p,n);
				}
			 	if ( ((Pptr)p)->typ->tconst() ) {
					if (oper) error("%sM%n of%t",es,n,((Pptr)p)->typ); //(#) Clipped at "((Pptr)p)".
					return 0;
				}
			}
			goto xx;
		case NAME:
			n = (Pname)ee;
		xx:
			if (deref || oper==0) return 1;
			switch (oper) {
			case ADDROF:
			case G_ADDROF:
			{	Pfct f = (Pfct)n->tp;
				if (n->n_sto == REGISTER) {
					if (oper) error("& register%n",n);
					return 0;
				}
				if (f == 0) {
					if (oper) error("& label%n",n);
					return 0;
				}
			/*	if (f->base == OVERLOAD) {
					if (oper) error("& overloaded%n",n);
					return 0;
				}
			*/
				if (n->n_stclass == ENUM) {
					if (oper) error("& enumerator%n",n);
					return 0;
				}
				n->n_used--;
				n->take_addr();
				if (n->n_evaluated
				|| (f->base==FCT && f->f_inline) ) {
					/* address of const or inline: allocate it */ //(#) Clipped at "allocate it ".
					Pname nn = new name;
					if (n->n_evaluated) {
						n->n_evaluated = 0;	/* use allocated version */ //(#) Clipped at "use allo".
						n->n_initializer = new expr(IVAL,(Pexpr)n->n_val,0);
					}
					*nn = *n;
					nn->n_sto = STATIC;
					nn->n_list = dcl_list;
					dcl_list = nn;
				}
				break;
			}
			case ASSIGN:
				n->n_used--;
				n->assign();
				break;
			default:	/* incr ops, and asops */
				if (cc->tot && n==cc->c_this) {
					error("%n%k",n,oper);
					return 0;
				}
				n->assign();
			}
			return 1;
		}
	}
}

Pexpr Ninit;

bit gen_match(Pname n, Pexpr arg)
/*
	look for an exact match between "n" and the argument list "arg" 
*/
{
	Pfct f = (Pfct) n->tp;
	register Pexpr e;
	register Pname nn;

	for (e=arg, nn=f->argtype; e; e=e->e2, nn=nn->n_list) {
		Pexpr a = e->e1;
		Ptype at = a->tp;
		if (at->base == ANY) return 0;
		if (nn == 0) return f->nargs_known==ELLIPSIS;

		Ptype nt = nn->tp;

		switch (nt->base) {
		case RPTR:
			if (nt->check(at,COERCE)) {
				if (((Pptr)nt)->typ->check(at,0)) return 0;
			}
			break;
		default:
			if (nt->check(at,COERCE)) return 0;
		}
	}

	if (nn) {
		Ninit = nn->n_initializer;
		return Ninit!=0;
	}
	return 1;
}

Pname Ncoerce;

bit can_coerce(Ptype t1, Ptype t2)
/*	return number of possible coercions of t2 into t1,
	Ncoerce holds a coercion function (not constructor), if found
*/
{
/*error('d',"can_coerce %t->%t",t1,t2);*/
	Ncoerce = 0;
	if (t2->base == ANY) return 0;
	switch (t1->base) {
	case RPTR:
	rloop:
		switch (t2->base) {
		case TYPE:
			t2 = ((Pbase)t2)->b_name->tp;
			goto rloop;
	//	case VEC:
	//	case PTR:
	//	case RPTR:
	//		if (t1->check(t2,COERCE) == 0) return 1;
		default:	
		{	Ptype tt2 = t2->addrof();
			if (t1->check(tt2,COERCE) == 0) return 1;
			Ptype tt1 = ((Pptr)t1)->typ;
			int i = can_coerce(tt1,t2);
			return i;
		}
		}
	}

	Pname c1 = t1->is_cl_obj();
	Pname c2 = t2->is_cl_obj();
	int val = 0;

	if (c1) {
		Pclass cl = (Pclass)c1->tp;
		if (c2 && c2->tp==cl) return 1;

		/*	look for constructor
				with one argument
				or with default for second argument
			of acceptable type
		*/
		Pname ctor = cl->has_ctor();
		if (ctor == 0) goto oper_coerce;
		register Pfct f = (Pfct)ctor->tp;

		switch (f->base) {
		case FCT:
			switch (f->nargs) {
			case 1:
			one:
				if (f->argtype->tp->check(t2,COERCE)==0) val = 1;
				goto oper_coerce;
			default:
				if (f->argtype->n_list->n_initializer) goto one;
			case 0:
				goto oper_coerce;
			}
		case OVERLOAD:
		{	register Plist gl;

			for (gl=Pgen(f)->fct_list; gl; gl=gl->l) {	/* look for match */ //(#) Clipped at "look for".
				Pname nn = gl->f;
				Pfct ff = (Pfct)nn->tp;
				switch (ff->nargs) {
				case 0:
					break;
				case 1:
				over_one:
					if (ff->argtype->tp->check(t2,COERCE)==0) val = 1; //(#) Clipped at "==0) v".
					if (ff->argtype->tp->base == RPTR
					&& ((Pptr)ff->argtype->tp)->typ->check(t2,COERCE) == 0) { //(#) Clipped at "check(t2,C". Not verified.
						val = 1;
						goto oper_coerce;
					}
					break;
				default:
					if (ff->argtype->n_list->n_initializer) goto over_one; //(#) Clipped at "got".
				}
			}
			goto oper_coerce;
		}
		default:
			error('i',"cannot_coerce(%k)\n",f->base);
		}
	}
oper_coerce:
	if (c2) {	
		Pclass cl = (Pclass)c2->tp;
		for (register Pname on=cl->conv; on; on=on->n_list) {
/*error('d'," oper_coerce%n %t %d",on,(on)?on->tp:0,on);*/
			Pfct f = (Pfct)on->tp;
			if (t1->check(f->returns,COERCE) == 0) {
				Ncoerce = on;
				val++;
			}
		}
	}

	if (val) return val;
	if (t1->check(t2,COERCE)) return 0;
	return 1;
}

int gen_coerce(Pname n, Pexpr arg)
/*
	look to see if the argument list "arg" can be coerced into a call of "n"
	1: it can
	0: it cannot or it can be done in more than one way
*/
{
	Pfct f = (Pfct) n->tp;
	register Pexpr e;
	register Pname nn;
/*error('d',"gen_coerce%n %d",n,arg);*/
	for (e=arg, nn=f->argtype; e; e=e->e2, nn=nn->n_list) {
		if (nn == 0) return f->nargs_known==ELLIPSIS;
		Pexpr a = e->e1;
		Ptype at = a->tp;
		int i = can_coerce(nn->tp,at);
/*error('d',"a1 %k at%t argt%t -> %d",a->base,at,nn->tp,i);*/
		if (i != 1) return 0;
	}
	if (nn && nn->n_initializer==0) return 0;
	return 1;
}


Pname Nover;
int Nover_coerce;

int over_call(Pname n, Pexpr arg)
/*	
	return 2 if n(arg) can be performed without user defined coercion of arg
	return 1 if n(arg) can be performed only with user defined coercion of arg
	return 0 if n(arg) is an error
*/
{	
	register Plist gl;
	Pgen g = (Pgen) n->tp;
	if (arg && arg->base!= ELIST) error('i',"ALX");
/*error('d',"over_call%n base%k arg%d%k", n, g->base, arg, arg?arg->tp->base:0);*/
	Nover_coerce = 0;
	switch (g->base) {
	default:	 error('i',"over_call(%t)\n",g);
	case OVERLOAD:	break;
	case FCT:
		Nover = n;
		Ninit = 0;
		if (gen_match(n,arg) && Ninit==0) return 2;
		if (gen_coerce(n,arg)) return 1;
		return 0;
	}

	for (gl=g->fct_list; gl; gl=gl->l) {		/* look for match */
		Nover = gl->f;
		Ninit = 0;
/*error('d',"over_call: gen_match(%n,%k) %d",Nover,arg->e1->base,gen_match(Nover,arg->e1->base));*/ //(#) Clipped at "(Nover,arg". Not verified.
		if (gen_match(Nover,arg) && Ninit==0) return 2;
	}

	Nover = 0;
	for (gl=g->fct_list; gl; gl=gl->l) {		/* look for coercion */
		Pname nn = gl->f;
/*error('d',"over_call: gen_coerce(%n,%k) %d",nn,arg->e1->base,gen_coerce(nn,arg));*/ //(#) Clipped at "(nn,arg));*".
		if (gen_coerce(nn,arg)) {
			if (Nover) {
				Nover_coerce = 2;
				return 0;		/* ambiguous */
			}
			Nover = nn;
		}
	}

	return Nover ? 1 : 0;
}


Ptype expr.fct_call(Ptable tbl)
/*
	check "this" call:
		 e1(e2)
	e1->typ() and e2->typ() has been done
*/
{
	Pfct f;
	Pname fn;
	int x;
	int k;
	Pname nn;
	Pexpr e;
	Ptype t;
	Pexpr arg = e2;
	Ptype t1;
	int argno;
	Pexpr etail = 0;
	Pname no_virt;	/* set if explicit qualifier was used: c::f() */
/*error('d',"fct_call");*/
	switch (base) {
	case CALL:
	case G_CALL:
		break;
	default:
		error('i',"fct_call(%k)",base);
	}

	if (e1==0 || (t1=e1->tp)==0) error('i',"fct_call(e1=%d,e1->tp=%t)",e1,t1);
	if (arg && arg->base!=ELIST) error('i',"badAL%d%k",arg,arg->base);

	switch (e1->base) {
	case NAME:
		fn = (Pname)e1;
		no_virt = fn->n_qualifier;
		break;
	case REF:
	case DOT:
		fn = e1->mem;
		no_virt = fn->n_qualifier;
		break;
	default:
		fn = 0;
		no_virt = 0;
	};
/*error('d',"fn%n t1%k",fn,t1->base);*/
	switch (t1->base) {
	default:
		error("call of%n;%n is a%t)",fn,fn,e1->tp);

	case ANY:
		return any_type;
	
	case OVERLOAD:
	{	register Plist gl;
		Pgen g = (Pgen) t1;
		Pname found = 0;

		for (gl=g->fct_list; gl; gl=gl->l) {	/* look for match */
			register Pname nn = gl->f;
/*fprintf(stderr,"gen_match %s %d\n",nn->string?nn->string:"?",arg->base);*/
			if (gen_match(nn,arg)) {
				found = nn;
				goto fnd;
			}
		}

		for (gl=g->fct_list; gl; gl=gl->l) {	/* look for coercion */
			register Pname nn = gl->f;
/*fprintf(stderr,"gen_coerce %s %d\n",nn->string?nn->string:"?",arg->base);*/
			if (gen_coerce(nn,arg)) {
				if (found) {
					error("ambiguousA for overloaded%n",fn);
					goto fnd;
				}
				found = nn;
			}
		}
	
	fnd:
//error('d',"found%n",found);
		if (found) {
			Pbase b;
			Ptable tblx;

			f = (Pfct)found->tp;
			fct_name = found;

			/* is fct_name visible? */
//error('d',"e1 %d%k",e1,e1?e1->base:0);
			switch (e1->base) {
			case REF:
				if (e1->e1 == 0) break;	/* constructor: this==0 */
				b = (Pbase) ((Pptr)e1->e1->tp)->typ; goto xxxx;
			case DOT:
				b = (Pbase)e1->e1->tp;
			xxxx:
				switch (b->base) {
				case TYPE:	b = (Pbase) b->b_name->tp; goto xxxx; //(#) Clipped at "goto xxx".
				case ANY:	break;
				case COBJ:	tblx = b->b_table;
				}

				if ( tblx->lookc(g->string,0) == 0)
					error('i',"fct_call overload check");
//error('d',"scope %d epriv %d ebase %d cc %d",found->n_scope,Epriv,Ebase,cc);
				switch (found->n_scope) {
				case 0:
					if (Epriv
					&& Epriv!=cc->cot
					&& !Epriv->has_friend(cc->nof)) {
						error("%n is private",found);
						break;
					}
					/* no break */
				case PUBLIC:
					if (Ebase
					&& (cc->cot==0
						|| ( Ebase!=cc->cot->clbase->tp
						&& !Ebase->has_friend(cc->nof)))
					) {
					  error("%n is from a privateBC",found);
					}
				}
			}
		}
		else {
			error("badAL for overloaded%n",fn);
			return any_type;
		}
		break;
	}
	case FCT:
		f = (Pfct)t1;
		if (fn)	fct_name = fn;
		break;
	}

	if (no_virt) fct_name = 0;

	t = f->returns;
	x = f->nargs;
	k = f->nargs_known;
/*error('d',"fct_name%n",fct_name);*/

	if (k == 0) return t;
/*
	if (arg == 0) {
		switch (x) {
		default:	error("AX for%n",fn);
		case 0:		return t;
		}
	}
*/

	for (e=arg, nn=f->argtype, argno=1; e||nn; nn=nn->n_list, e=etail->e2, argno++) { //(#) Clipped at "e=etail->e2, argn".
		Pexpr a;

		if (e) {
			a = e->e1;
/*error('d',"e %d%k a %d%k e2 %d",e,e->base,a,a->base,e->e2);*/
			etail = e;

			if (nn) {	/* type check */
				Ptype t1 = nn->tp;
			lx:
/*error('d',"lx: t1%t a->tp%t",t1,a->tp);*/
				switch (t1->base) {
				case TYPE:
					t1 = ((Pbase)t1)->b_name->tp;
					goto lx;
				case RPTR:
					e->e1 = ref_init(Pptr(t1),a,tbl);
					break;
				case COBJ:
					e->e1 = class_init(0,t1,a,tbl);
					break;
				case ANY:
					return t;
		case PTR:
		{	Pfct ef = (Pfct)((Pptr)t1)->typ;
			if (ef->base == FCT) {
				Pfct f;
				Pname n = 0;
				switch (a->base) {
				case NAME:
					f = (Pfct)a->tp;
					switch (f->base) {
					case FCT:
					case OVERLOAD:
						e->e1 = new expr(G_ADDROF,0,a);
						e->e1->tp = f;
					}
					n = Pname(a);
					goto ad;
				case DOT:
				case REF:
					f = (Pfct)a->mem->tp;
					switch (f->base) {
					case FCT:
					case OVERLOAD:
						n = Pname(a->mem);
						a = new expr(G_ADDROF,0,a);
						e->e1 = a->typ(tbl);
					}
					goto ad;
				case ADDROF:
				case G_ADDROF:
					f = (Pfct)a->e2->tp;
				ad:
					if (f->base == OVERLOAD) {
						Pgen g = (Pgen)f;
						n = g->find(ef);
						if (n == 0) {
							error("cannot deduceT for &overloaded %s()",g->string); //(#) Clipped at "deduceT for &".
							return any_type;
						}
						e->e1->e2 = n;
					}
					if (n) n->lval(ADDROF);
				}
				break;
				
			}
			goto def;
		}
				case CHAR:
				case SHORT:
				case INT:
					if (a->base==ICON && a->tp==long_type)
						error('w',"long constantA for%n,%kX",fn,t1->base); //(#) Clipped at "for%n,%kX".
				case LONG:
					if (((Pbase)t1)->b_unsigned
					&& a->base==UMINUS
					&& a->e2->base==ICON)
						error('w',"negativeA for%n, unsignedX",fn); //(#) Clipped at "unsigne".
				default:
				def:
					{	Pname cn;
						int i;
						if ((cn=a->tp->is_cl_obj())
						&& (i=can_coerce(t1,a->tp))
						&& Ncoerce) {
							if (1 < i) error("%d possible conversions for%nA%d",i,fn,argno); //(#) Clipped at "%d possib".
/*error('d',"%t<-%t",t1,a->tp);*/
							Pclass cl = (Pclass)cn->tp;
							Pref r = new ref(DOT,a,Ncoerce); //(#) Clipped at "DOT,e,Ncoe".
							Pexpr c = new expr(G_CALL,r,0); //(#) Clipped at "G_CALL,r".
							c->fct_name = Ncoerce;
							c->tp = t1;
							e->e1 = c;		
							return t1;
						}
					}
					if (t1->check(a->tp,ARG)) {
						if (arg_err_suppress==0) error("badA %dT for%n:%t (%tX)",argno,fn,a->tp,nn->tp); //(#) Clipped at "bad".
						return any_type;
					}
				}
			}
			else {
				if (k != ELLIPSIS) {
					if (arg_err_suppress==0) error("unX %dA for%n",argno,fn); //(#) Clipped at "%dA for".
					return any_type;
				}
				return t;
			}
		}
		else {	/* default argument? */
			a = nn->n_initializer;

			if (a == 0) {
				if (arg_err_suppress==0) error("A %d ofT%tX for%n",argno,nn->tp,fn); //(#) Clipped at '"A %d of T%tX for%n",'.
				return any_type;
			}
			e = new expr(ELIST,a,0);
			if (etail)
				etail->e2 = e;
			else
				e2 = e;
			etail = e;
		}
	}

	return t;
}

int refd;

Pexpr ref_init(Pptr p, Pexpr init, Ptable tbl)
/*
	initialize the "p" with the "init"
*/
{
	register Ptype it = init->tp;
	Ptype p1;
	Pname c1;
	Pexpr a;

rloop:
/*error('d',"rloop: %d%k",it,it->base);*/
	switch (it->base) {
	case TYPE:
		it = ((Pbase)it)->b_name->tp; goto rloop;
//	case VEC:
//	case PTR:
//		if (p->check(it,ASSIGN) == 0) return init;
//		break;
	default:
		{	Ptype tt = it->addrof();
			if (p->check(tt,ASSIGN) == 0) {
				if (init->lval(0)) return init->address();
				if (init->base==G_CALL	/* &inline function call? */ //(#) Clipped at "&inline function call? *".
				&& init->fct_name
				&& ((Pfct)init->fct_name->tp)->f_inline )
					return init->address();
				p1 = p->typ;
				goto xxx;
			}
		}
	}

	p1 = p->typ;
	c1 = p1->is_cl_obj();

	if (c1) {
		refd = 1;	/* disable itor */
		a = class_init(0,p1,init,tbl);
		refd = 0;
		if (a == init) goto xxx;
		switch (a->base) {
		case G_CALL:
		case CM:
			init = a;
			goto xxx;
		}
		return a->address();
	}

	if (p1->check(it,ASSIGN)) {
		error("badIrT:%t (%tX)",it,p);
		init->tp = any_type;
		return init;
	}

xxx:
/*error('d',"xxx: %k",init->base);*/
	switch (init->base) {
	case NAME:
	case DEREF:
	case REF:
	case DOT:			/* init => &init */
		init->lval(ADDROF);
		return init->address();
	case CM:
/*error('d',"cm%k",init->e2->base);*/
		switch (init->e2->base) {	/* (a, b) => (a, &b) */
		case NAME:
		case DEREF:
			return init->address();
		}
	default:			/* init = > ( temp=init, &temp) */
	{	Ptable otbl = tbl;
		if (Cstmt) {	/*	make Cstmt into a block */
			if (Cstmt->memtbl == 0) Cstmt->memtbl = new table(4,tbl,0);
			tbl = Cstmt->memtbl;
		}
		char* s = make_name('I');
		Pname n = new class name(s);

/*error('d',"ref_init tmp %s n=%d tbl %d init=%d%k",s,n,tbl,init,init->base);*/
		if (tbl == gtbl) error('s',"Ir for global reference not an lvaue");		
		n->tp = p1;
		n = n->dcl(tbl,ARG); /* no initialization! */
		n->n_scope = FCT;
		n->assign();
		a = n->address();
		Pexpr as = new class expr(ASSIGN,n,init);
		a = new class expr(CM,as,a);
		a->tp = a->e2->tp;
		tbl = otbl;
		return a;
	}
	}
}

Pexpr class_init(Pexpr nn, Ptype tt, Pexpr init, Ptable tbl)
/*
	initialize "nn" of type "tt" with "init"
	if nn==0 make a temporary,
	nn may not be a name
*/
{	Pname c1 = tt->is_cl_obj();
	Pname c2 = init->tp->is_cl_obj();

/*error('d',"class_init%n%n%n refd=%d",nn,c1,c2,refd);*/
	if (c1) {
		if (c1!=c2
		|| (refd==0 && Pclass(c1->tp)->has_itor())) {
			/*	really ouht to make a temp if refd,
				but ref_init can do that
			*/
			int i = can_coerce(tt,init->tp);
			if (Ncoerce) {
				if (1 < i) {
					error("%d possible ways of making a%n from a%t",i,c1,init->tp); //(#) Clipped at "a%n from ".
					return init;
				}
/*error('d',"coerce%n=(%d%k).%n",nn,init,init->base,Ncoerce);*/
				switch (init->base) {
				case CALL:
				case G_CALL:
				case CM:
				case NAME:	/* init.coerce() */	
				{	Pref r = new ref(DOT,init,Ncoerce);
					Pexpr c = new expr(G_CALL,r,0);
					c->fct_name = Ncoerce;
					init = c;
					break;
				}
				default:	/* (temp=init,temp.coerce()) */
				{	Ptable otbl = tbl;
					if (Cstmt) { /*	make Cstmt into a block */
						if (Cstmt->memtbl == 0) Cstmt->memtbl = new table(4,tbl,0); //(#) Clipped at "== 0) Cstmt->memt".
						tbl = Cstmt->memtbl;
					}
					char* s = make_name('U');
					Pname tmp = new name(s);
					tmp->tp = init->tp;
					tmp = tmp->dcl(tbl,ARG); /* no init! */
					tmp->n_scope = FCT;
					Pexpr ass = new expr(ASSIGN,tmp,init);
					ass->tp = tt;
					Pref r = new ref(DOT,tmp,Ncoerce);
					Pexpr c = new expr(G_CALL,r,0);
					c->fct_name = Ncoerce;
					init = new expr(CM,ass,c);
					tbl = otbl;	
				}
				}
				return init->typ(tbl);
			}
			Pexpr a = new class expr(ELIST,init,0);
			a = new class texpr(VALUE,tt,a);
			a->e2 = nn;
			a = a->typ(tbl);
/*error('d',"class_init%n: %k %t",nn,a->base,tt);*/
			return a;
		}
/*error('d',"class_init%n: init%t",nn,init->base,init->tp);*/
		return init;
	}

	if (tt->check(init->tp,ASSIGN) && refd==0) {
		error("badIrT:%t (%tX)",init->tp,tt);
		init->tp = any_type;
	}
	return init;
}

int char_to_int(char* s)
/*	assume s points to a string:
		'c'
	or	'\c'
	or	'\0'
	or	'\ddd'
	or multi-character versions of the above
*/
{
	register int i = 0;
	register char c, d, e;

	switch (*s) {
	default:
		error('i',"char constant store corrupted");
	case '`':
		error('s',"bcd constant");
		return 0;
	case '\'':
		break;
	}

	forever			/* also handle multi-character constants */
	switch (c = *++s) {
	case '\'':
		return i;
	case '\\':			/* special character */
		switch (c = *++s) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7':	/* octal representation */
			c -= '0';
			switch (d = *++s) {		/* try for 2 */
				
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7':
				d -= '0';
				switch (e = *++s) {	/* try for 3 */
					
				case '0': case '1': case '2': case '3': case '4':
				case '5': case '6': case '7':
					c = c*64+d*8+e-'0';
					break;
				default:
					c = c*8+d;
					s--;
				}
				break;
			default:
				s--;
			}
			break;
		case 'b':
			c = '\b';
			break;
		case 'f':
			c = '\f';
			break;
		case 'n':
			c = '\n';
			break;
		case 'r':
			c = '\r';
			break;
		case 't':
			c = '\t';
			break;
		case '\\':
			c = '\\';
			break;
		case '\'':
			c = '\'';
			break;
		}
		/* no break */
	default:
		if (i) i <<= BI_IN_BYTE;
		i += c;
	}
}

const A10 = 'A'-10;
const a10 = 'a'-10;

int str_to_int(register char* p)
/*
	read decimal, octal, or hexadecimal integer
*/
{
	register c;
	register i = 0;

	if ((c=*p++) == '0') {
		switch (c = *p++) {
		case 0:
			return 0;

		case 'l':
		case 'L':	/* long zero */
			return 0;

		case 'x':
		case 'X':	/* hexadecimal */
			while (c=*p++)
				switch (c) {
				case 'l':
				case 'L':
					return i;
				case 'A':
				case 'B':
				case 'C':
				case 'D':
				case 'E':
				case 'F':
					i = i*16 + c-A10;
					break;
				case 'a':
				case 'b':
				case 'c':
				case 'd':
				case 'e':
				case 'f':
					i = i*16 + c-a10;
					break;
				default:
					i = i*16 + c-'0';
				}
			return i;

		default:	/* octal */
			do 
				switch (c) {
				case 'l':
				case 'L':
					return i;
				default:
					i = i*8 + c-'0';
				}
			while (c=*p++);
			return i;
		}
	}	
				/* decimal */
	i = c-'0';
	while (c=*p++)
		switch (c) {
		case 'l':
		case 'L':
			return i;
		default:
			i = i*10 + c-'0';
		}
	return i;
	
		
}

char* Neval;

int expr.eval()
{
	if (Neval) return 1;

	switch (base) {
	case ZERO:	return 0;
	case IVAL:	return (int)e1;
	case ICON:	return str_to_int(string);
	case CCON:	return char_to_int(string);
	case FCON:	Neval = "float in constant expression"; return 1;
	case STRING:	Neval = "string in constant expression"; return 1;
	case EOBJ:	return ((Pname)this)->n_val;
	case SIZEOF:	return tp2->tsizeof();
	case NAME:
	{	Pname n = (Pname)this; 
		if (n->n_evaluated) return n->n_val;
		Neval = "cannot evaluate constant";
		return 1;
	}
	case ICALL:
		if (e1) {
			il->i_next = curr_icall;
			curr_icall = il;
			int i = e1->eval();
			curr_icall = il->i_next;
			return i;
		}
		Neval = "void inlineF";
		return 1;
	case ANAME:
	{	Pname n = (Pname)this;
		int argno = n->n_val;
		Pin il;
		for (il=curr_icall; il; il=il->i_next)
			if (il->i_table == n->n_table) goto aok;
		goto bok;
	aok:
		if (il->local[argno]) {
	bok:
			Neval = "inlineF call too complicated for constant expression"; //(#) Clipped at "constant expressi".
			return 1;
		}
		Pexpr aa = il->arg[argno];
		return aa->eval();
	}
	case CAST:
	{	int i = e1->eval();
		Neval = "cast in constant expression";
		return i;
	}
	case UMINUS:
	case NOT:
	case COMPL:
	case PLUS:
	case MINUS:
	case MUL:
	case LS:
	case RS:
	case NE:
	case LT:
	case LE:
	case GT:
	case GE:
	case AND:
	case OR:
	case ER:
	case DIV:
	case MOD:
	case QUEST:
	case EQ:
	case ANDAND:
	case OROR:
		break;
	default:
		Neval = "bad operator in constant expression";
		return 1;
	}

	int i1 = (e1) ? e1->eval() : 0;
	int i2 = (e2) ? e2->eval() : 0;

	switch (base) {
	case UMINUS:	return -i2;
	case NOT:	return !i2;
	case COMPL:	return ~i2;
	case CAST:	return i1;
	case PLUS:	return i1+i2;
	case MINUS:	return i1-i2;
	case MUL:	return i1*i2;
	case LS:	return i1<<i2;
	case RS:	return i1>>i2;
	case NE:	return i1!=i2;
	case EQ:	return i1==i2;
	case LT:	return i1<i2;
	case LE:	return i1<=i2;
	case GT:	return i1>i2;
	case GE:	return i1>=i2;
	case AND:	return i1&i2;
	case OR:	return i1|i2;
	case OROR:	return i1||i2;
	case ER:	return i1^i2;
	case MOD:	return (i2==0) ? 1 : i1%i2;
	case QUEST:	return (cond->eval()) ? i1 : i2;
	case DIV:	if (i2==0) {
				Neval = "divide by zero";
				return 1;
			}
			return i1/i2;
	}
}

bit classdef.has_friend(Pname f)
/*
	does this class have function "f" as its friend?
*/
{
	Plist l;
	Ptable ctbl = f->n_table;
/*fprintf(stderr,"(%d %s)->has_friend(%d %s)\n",this,string,f,(f)?f->string:""); fflush(stderr);*/ //(#) Clipped at "; ffl".
	for (l=friend_list; l; l=l->l) {
		Pname fr = l->f;
/*fprintf(stderr,"fr %d %d %d\n",fr,fr->tp,fr->tp->base); fflush(stderr);*/
		switch (fr->tp->base) {
		case CLASS:
			if (((Pclass)fr->tp)->memtbl == ctbl) return 1;
			break;
		case COBJ:
			if (((Pbase)fr->tp)->b_table == ctbl) return 1;
			break;
		case FCT:
			if (fr == f) return 1;
			break;
		case OVERLOAD:
		{/*	Pgen g = (Pgen)fr->tp;
			Plist ll;
			for (ll=g->fct_list; ll; ll=ll->l) {
				if (ll->f == f) return 1;
			}*/
			l->f = fr = ((Pgen)fr->tp)->fct_list->f; /* first fct */
			if (fr == f) return 1;
			break;
		}
		default:
			error('i',"bad friend %k",fr->tp->base);
		}
	}
	return 0;
}
