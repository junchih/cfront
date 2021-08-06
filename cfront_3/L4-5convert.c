#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "L4-5convert.h"

#define LMAX 1024
static char buf[LMAX];
static int lineno = 1;
static char* filename;
static FILE *infd, *outfd;
static int debug = 0;

#define GET(c) (c = getc(infd))
inline void
PUT( char c )
{
	if ( c == '\n' ) ++lineno;
	putc(c,outfd);
}
inline void
PUT( char* s )
{
	// assumes no newlines in s
	fprintf(outfd,"%s",s);
}

inline void
error( const char* fmt, const char* s )
{
	if ( filename ) fprintf(stderr,"\"%s\":",filename);
	if ( lineno ) fprintf(stderr,"line %d:",lineno);
	putc(' ',stderr);
	fprintf(stderr,fmt,s);
	putc('\n',stderr);
}
inline void
error( const char* fmt, const char* s, int c )
{
	if ( filename ) fprintf(stderr,"\"%s\":",filename);
	if ( lineno ) fprintf(stderr,"line %d:",lineno);
	putc(' ',stderr);
	fprintf(stderr,fmt,s,c);
	putc('\n',stderr);
}

static int
ptskip( char* s )
{
	for ( char** p = ptskipbuf; *p; ++p )
		if ( strcmp(s,*p) == 0 ) return 1;
	return 0;
}
static int
ptmacro( char* s )
{
	for ( char** p = ptmacrobuf; *p; ++p )
		if ( strcmp(s,*p) == 0 ) return 1;
	return 0;
}

void
ptlex()
{
	static int saved = EOF;
	static int nestlevel = 0; // nest level of pt macro
	int plevel = nestlevel?1:0; // paren level within pt macro arg
	int dtor = 0; // set when lsat non-space char was ~
	int c;

	for(;;) {
	    if ( saved == EOF ) GET(c);
	    else { c = saved; saved = EOF; }
	    switch ( c ) {
	    case EOF: return;
	    case '(':
		PUT(c);
		++plevel;
		dtor = 0;
		break;
	    case ')':
		if ( --plevel <= 0 && nestlevel ) return;
		PUT(c);
		dtor = 0;
		break;
	    case '/': // check for comment
		PUT(c);
		switch ( GET(c) ) {
		default:
			saved = c;
			dtor = 0;
			break;
		case '/':
			PUT(c);
			while ( GET(c) != '\n' && c != EOF ) PUT(c);
			if ( c != EOF ) PUT(c);
			break;
		case '*':
			PUT(c);
			while ( GET(c) != EOF ) {
			    PUT(c);
			    while ( c == '*' ) {
				GET(c);
				if ( c != EOF ) PUT(c);
				if ( c == '/' ) goto endcom;
			    }
			}
			endcom:
			break;
		}
		break;
	    case '#':
		PUT(c);
		while ( GET(c) != EOF ) {
			PUT(c);
			if ( c == '\n' ) break;
		}
		break;
	    case '~':
		PUT(c);
		dtor = 1;
		break;
	    default:
		if ( isalpha(c) || c == '_' ) {
			char* p = buf;
			*p++ = c;
			GET(c);
			while ( isalnum(c) || c == '_' )
				{ *p++ = c; GET(c); }
			*p = 0;
//fprintf(stderr,"buf:'%s', dtor:%d\n",buf,dtor);
			if ( dtor ) {
				// last non-space char was a ~
				// don't translate ~name() to ~name<>
				PUT(buf);
				saved = c;
			} else if ( ptskip(buf) ) {
				// Xdeclare(id) or Ximplement(id)
				// delete from output
				while ( isspace(c) ) GET(c);
				if ( c == '(' ) {
				        int pl = 1;
					if ( debug )
						error("DEBUG: deleting %s",buf);
					while ( GET(c) != EOF ) {
						if ( c == '(' ) ++pl;
						else if ( c == '\n' ) ++lineno;
						else if ( c == ')' )
							if ( --pl<=0 ) break;
					}
				} else {
					error("%s followed by '%c'; expecting '('",buf,c);
					PUT(buf);
					PUT(c);
					dtor = 0;
					break;
				}
			} else if ( ptmacro(buf) ) {
				PUT(buf);
				while ( isspace(c) ) { PUT(c); GET(c); }
				if ( c != '(' ) {
					error("%s followed by '%c'; expecting '('",buf,c);
					PUT(c);
					dtor = 0;
					break;
				}
				if ( debug )
					error("DEBUG: converting %s",buf);
				PUT('<');
				++nestlevel;
				ptlex();
				--nestlevel;
				PUT("> ");
			} else {
				PUT(buf);
				saved = c;
			}
			dtor = 0;
		} else { // not an identifier
			PUT(c);
			if ( !isspace(c) && c!='\n' ) dtor = 0;
		}
		break;
	    } // switch
	} // for
}


#include "Tmppath.h"
#include <string.h>

main( int argc, char **argv )
{
	if ( argc == 1 ) {
		lineno = 1;
		filename = 0;
		infd = stdin;
		outfd = stdout;
		ptlex();
	} else
	for ( int i = 1; i < argc; ++i ) {
	    if ( strcmp(argv[i],"-d") == 0 )
		debug = 1;
	    else {
		Tmppath tf("_pt_");
		lineno = 0; // suppress line in error print
		filename = argv[i];
		infd = fopen(filename,"r");
		outfd = fopen(tf,"w");
		if ( infd == NULL ) {
			error("can't open %s",filename);
			fclose(outfd);
			continue;
		}
		if ( outfd == NULL ) {
			error("can't open %s",(const char*)tf);
			fclose(infd);
			continue;
		}
		lineno = 1;
		ptlex();
		fclose(infd); fclose(outfd);
		char* s = new char[tf.length() + strlen(filename) + 4];
		sprintf(s,"mv %s %s", (const char*)tf, filename);
		system(s);
		delete s;
	    }
	}
}
