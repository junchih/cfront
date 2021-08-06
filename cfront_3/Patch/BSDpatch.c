/*ident	"@(#)cls4:Patch/BSDpatch.c	1.3" */
/*******************************************************************************
 
C++ source for the C++ Language System, Release 3.0.  This product
is a new release of the original cfront developed in the computer
science research center of AT&T Bell Laboratories.

Copyright (c) 1993  UNIX System Laboratories, Inc.
Copyright (c) 1991, 1992 AT&T and UNIX System Laboratories, Inc.
Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.

THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
Laboratories, Inc.  The copyright notice above does not evidence
any actual or intended publication of such source code.

*******************************************************************************/
/*
	- general speed up by reading symbol table at once
	- Added support for alliant compiler and linker
	- added support for entries of the form __link*
	  as well as just __link.  This provides support for generating
	  __link entries on machines in which static data symbols are
	  removed from the symbol table by the compiler if they are not
	  referenced.  (For example, by Alliant FX/C `optimizations')
*/

/*patch: Patch an a.out to ensure that static constructors are called.
Currently this is in good-old-C.

	The program is passed one argument, the name of an executable
	C++ program.  It first reads the symbol table, remembering
	all symbols of the name __link.  
	  Each of these symbols points to a structure of the form:
		struct __linkl {
			struct __linkl *next;	//next link in the chain
			int (*ctor)();		//ptr to ctor function
			int (*dtor)();		//ptr to dtor function
		};
	cfront puts one of these in each dot-o.  Patch finds them,
	and chains them together by writing
	(into the actual a.out) values for the "next"
	pointers.  A pointer to the start of the chain is written
	into the struct __linkl pointer named __head.
	 _main will follow this chain at runtime and 
	use the ctor and dtor function pointers to call the static
	ctors and dtors.

	The program allows a debug option: patch -d <filename>
***************************************************************/
			
#include <stdio.h>
#include <a.out.h>
#if mc300|ibm032
#include <sys/param.h>
#endif /* mc300|ibm032 */

void fatal_error();     /*prints error message and breaks*/
int debug = 0;          /*1 iff debug option set*/
int found_main = 0;	/*1 iff _main() has been seen*/
long head = 0;	        /*Address of the __head symbol*/
long data_infile;	/*offset in file of the data segment*/
long data_pa;	        /*physical address of start of data segment*/
long zero = 0;
long previous;		/*used to create links*/
char *filename;		/*Name of the file being patched*/

#define SUCCESS          0
#define FAILURE          1
#define HEADSZ          sizeof(struct exec)
#define BEGINNING        0   /*flag for reading, seeking, writing*/
#define ST_ENTRYSZ      sizeof(struct nlist)
#define N_SYMS(x)       x.a_syms/ST_ENTRYSZ  /*no. of syms in table*/
#define MAX_LINKS 5000  /*may need to increase*/
long addrs[MAX_LINKS];	/*array of addresses of __link symbols*/
long *addr_ptr = addrs;

main(argc,argv)
int argc;
char *argv[];
{
	char *getname();	/*gets string from string table*/
	int stseek();           /*seeks to symbol table*/
	void data_addresses();  /*gets offset & physical address of data
				  section; depends on machine type*/
	struct exec header;     /*contains header info for a.out file*/
	FILE *fptr;
	long *symbol;		
	int x_sym;    	        /*index for accessing symbol table*/
        int n_syms;             /*number of symbols in table*/
        int sti_count = 0, std_count = 0,
            link_count = 0;     /*flags to check compilation*/
	struct nlist *syms;

       		/*Check for arguments*/
	if (argc == 3 && strcmp(argv[1], "-d")==0 )
	{
		filename = argv[2];
		debug = 1;
	}
	else if (argc == 2)
                filename = argv[1];
	else
		fatal_error("usage: patch file");

		/*Try to open the file & get header info*/
	if ( (fptr = fopen(filename,"r")) == NULL)
		fatal_error("cannot open file");
	else  fread ((char *)&header, HEADSZ, 1, fptr);

		/*Get physical address of data section at
		  runtime and offset in a.out file*/
	data_addresses (header, &data_infile, &data_pa);

                /*Seek to beginning of symbol table*/
        if (stseek (fptr, header) == FAILURE)
                fatal_error("cannot get symbol table");

                /*Find the ___head and ___link variables in the a.out;
                  fill array addrs*/
        n_syms = N_SYMS(header);
	syms = (struct nlist *)malloc(sizeof(*syms)*n_syms);
	if (fread((char *)syms, ST_ENTRYSZ,n_syms,fptr) != n_syms)
	  fatal_error("error reading symbol table");
	
        for (x_sym=0; x_sym < n_syms; x_sym++)
          {
            char *str;

                /*Read the symbol*/
            str = getname(fptr, header, syms[x_sym].n_un.n_strx);

	    if (*str++ != '_')
		continue;
	    if ((str[0] == '_') && (str[1] == '_')) {
		str += 2;
		if (strcmp(str, "head") == 0)
		{
		    if (debug)
			    printf("___head found at 0x%x\n",syms[x_sym].n_value);
		  head = syms[x_sym].n_value;
		}

		else if (strncmp(str, "link",4) == 0)
		{
		  if (addr_ptr >= addrs + MAX_LINKS)
		    fatal_error(" too many files");
		  *addr_ptr++ = syms[x_sym].n_value;
		  if (debug)
		  {
		    link_count++;
		    printf("%s found at 0x%x\n",str,syms[x_sym].n_value);
		  }
		}
		continue;
		}

	    if (strcmp(str, "main") == 0)
                found_main++;
            else if (debug)     
            {
                if (strncmp(str,"_sti",4) == 0)
                 	sti_count++;
                else if (strncmp(str,"_std",4) == 0)
			std_count++;
	    }
          }
	if (!head)
	{
		if (found_main == 0)
			fatal_error("_main() not found");
		else
		fatal_error("Bad _main() loaded- libC probably not set up for patch");
	}
			/*Now we have all of the __link pointers.
			  close the file, and reopen it for updating to
			  write the patches.  All hell will break loose
			  if someone writes the file in the meantime.*/
        fclose(fptr);

			/*If no symbols were found, quit*/
	if ( addr_ptr == addrs)
	{
		if(debug)
			printf("No __links found\n");
		exit(0);
	}

	if ( (fptr=fopen(filename, "r+")) == NULL)
		fatal_error(" can't reopen file");

			/*patch the first symbol*/
			/*seek to: physical adr. of symbol
				- physical adr of start of data
				+ file offset of start of data*/

	previous = head - data_pa + data_infile;

			/*Now, go thru the list of symbols. Each is
			  a pointer to the next link. Chain them up*/
			/*For non-obvious reasons, do this backwards.
			  This calls ctors from libraries first.*/

	for (symbol = addr_ptr - 1; symbol >= addrs; symbol --)
	{
			/*Update the previous pointer to point to this one.*/
		if(debug)
			printf("Write 0x%x at offset 0x%x\n",
			*symbol, previous );
		if (fseek(fptr, previous , 0))
			fatal_error("can't seek");
		if( fwrite((char *)symbol, sizeof(long), 1, fptr) == 0)
			fatal_error("can't write file");
		previous = *symbol - data_pa + data_infile;
	}
	if (symbol>=addrs) { fprintf(stderr,"FX/C BUG!\n"); exit(1); }
			/*Zero out the last symbol*/
	if(fseek(fptr, previous , 0))
		fatal_error("can't seek");
	if (fwrite((char *)&zero, sizeof(long), 1, fptr) == 0)
		fatal_error("can't write");
	if(debug)
	{	printf("Write 0 at offset 0x%x\n", previous );
		printf("sti_count = %d, std_count = %d, links = %d\n",
			sti_count,std_count,link_count);
	}
	fclose(fptr);
	exit(0);
}
void
fatal_error(message)
char * message;
{
	fprintf(stderr,"patch: file %s: %s\n", filename, message);
	exit(-1);
}


int stseek(fileptr, headinfo)
FILE *fileptr;
struct exec headinfo;
{
	if (!(fseek(fileptr, N_SYMOFF(headinfo), BEGINNING)))
		return (SUCCESS);

	else  return (FAILURE);
}	


/*Return string associated with index in string table.*/
char *getname (fiptr, head, index)
FILE *fiptr;
struct exec head;
long index;
{
	static char *strings=0,*malloc();
	static int strsize=0;
  
	if (strings == 0) {
	    int nread;
	    fread(&strsize,4,1,fiptr);
	    if ((strings = malloc(strsize)) == 0)
		fatal_error("malloc error");
	 
	    if (fseek(fiptr, N_STROFF(head), BEGINNING))
		    fatal_error("string table entry not found");
	    if ((nread=fread(strings,1,strsize,fiptr)) != strsize) {
		printf("strsize=%d,nread=%d\n",strsize,nread);
		fatal_error("string table read error");
		}
	    }
	if (index >= strsize) {
	    printf("index=%d, strsize=%d\n",index,strsize);
	    fatal_error("string seek past end");
	    }
	return(strings+index);
}



void data_addresses(head, infile, pa)        
struct exec head;
long *infile, *pa;
#ifdef mc300
{
	*infile = HEADSZ + head.a_text;

	if ((head.a_magic==NMAGIC) || (head.a_magic==ZMAGIC))
		/*Data will appear at next address where mod 4K bytes is 0*/
		*pa = head.a_text - (head.a_text % NBPG) + NBPG;

        else if (head.a_magic==OMAGIC)
  		/*Old method; text not write-protected*/
		*pa = (head.a_text);
	else fatal_error("bad magic number");
}
#endif		

#ifdef sun
{
	*infile = N_TXTOFF(head) + head.a_text;
	*pa = N_DATADDR(head);
}
#endif

#ifdef alliant
{
	*infile = N_TXTOFF(head) + head.a_text;
	*pa = head.a_data_addr;
}
#endif

#ifdef ibm032
{
	*infile = N_TXTOFF(head) + head.a_text;
	*pa = DATABASE;
}
#endif

#if defined(vax) || defined(tahoe)
{
	*infile = N_TXTOFF(head) + head.a_text;
	*pa = 	(head.a_magic==OMAGIC)
			? head.a_text
			: ((1023+head.a_text) & ~1023) ;

}
#endif
