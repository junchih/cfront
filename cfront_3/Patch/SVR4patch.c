/*ident	"@(#)cls4:Patch/SVR4patch.c	1.3" */
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
/*patch: Patch an a.out to ensure that static constructors are called.
Currently this is in good-old-C.

 This code uses -lelf, the Unix system V functions for accessing ELF files.
	The program is passed one argument, the name of an executable
	C++ program.  It first reads the ELF symbol table, remembering
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
***************************************************************/

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <libelf.h>

#define MAX_FILES 5000

void	fatal_error();
int	ScnhRead();
int	debug = 0;
int	found_main = 0;		/*1 iff _main() has been seen*/
char	*file;			/*Name of the file being patched*/


Elf32_Addr head = 0;		/*Adress of the __head symbol*/
Elf32_Off  data_infile;		/*offset in file of the data segment*/
Elf32_Addr data_pa;		/*physical adress of start of data segment*/
Elf32_Addr zero = 0;
Elf32_Addr previous;

Elf32_Addr addrs[MAX_FILES];	/*array of addresses of __link symbols*/
Elf32_Addr *addr_ptr = addrs;

main(argc , argv)
int argc;
char *argv[];
{
	Elf		*elf;
	Elf_Cmd		cmd;
	Elf32_Ehdr	*ehead;
	Elf32_Shdr	*shead;
	Elf32_Addr	*symbol;
	FILE*		fptr;
	int		fid, fid1;
	int		x_sym, undr, sym_cnt;
	int		strndx, symndx, symsz;

	if (argc == 3 && strcmp(argv[1], "-d")==0 ) {
		file = argv[2];
		debug = 1;
	} else if (argc == 2)
		file = argv[1];
	else
		fatal_error("usage: patch file");

	/* Try to open the file */
	if ( (fid = open(file, O_RDONLY)) < 0)
		fatal_error("cannot open file");
	fid1 = open(file, O_RDONLY); /* we need another fid opened on the
					same file in order to have an fid
					to pass to the elf_begin() function */

	/* Try to access the elf headers */
	if (elf_version(EV_CURRENT) == EV_NONE)
		fatal_error("Elf version out-of-date");

	cmd = ELF_C_READ;
	if ((elf = elf_begin(fid1, cmd, (Elf*)0)) == 0)
		fatal_error("cannot elf_begin file");

	if ((ehead = elf32_getehdr( elf )) == 0) {
		elf_end( elf );
		fatal_error("cannot get elf header");
	}

	strndx = ehead->e_shstrndx;

	if (ScnhRead( elf, strndx, ".data", &shead) == 0)
		fatal_error("cannot get .data header");
	
	/* Remember the start of data section, both the physical
	 * address at runtime, and the offset in the file
	 */
	data_infile = shead->sh_offset;
	data_pa = shead->sh_addr;

	if (debug) {
		printf("data in file: 0x%x\n", data_infile);
		printf("\taddr: 0x%x\n", data_pa);
	}

	/* Get the index of the symbol string table */
	if ((symndx = ScnhRead( elf, strndx, ".strtab", &shead)) == 0)
		fatal_error("cannot get .strtab header");

	/* Seek to the beginning of the symbol table*/
	if (ScnhRead( elf, strndx, ".symtab", &shead) == 0)
		fatal_error("cannot get symbol table");

	symsz = shead->sh_entsize;
	lseek( fid, shead->sh_offset, 0 );

	if (debug) {
		printf("symbol table in file: 0x%x\n", shead->sh_offset);
		printf("\taddr: 0x%x, num=%d\n", shead->sh_addr, shead->sh_info);
	}

	sym_cnt = shead->sh_size / symsz;

	/* Find the magic symbols in the a.out*/
        for ( x_sym = 0; x_sym < sym_cnt; ++x_sym ) {
		char	  *str;
		Elf32_Sym sym;

                /*read the symbol*/
		if ( read( fid, (char *)&sym, symsz ) != symsz)
			break;

		if (sym.st_value  == 0)
			continue;

		str = elf_strptr( elf, symndx, (size_t)sym.st_name);

 		undr=0;
		while ( str[0] == '_' ) { str++; undr++; }

		if (undr == 2) {
			if (strcmp(str, "head") == 0) {
				if (debug)
					printf("__head found at 0x%x\n", 
					sym.st_value);
				head = sym.st_value;
			}
			else if (strcmp(str, "link")==0) {
				if (addr_ptr >= addrs + MAX_FILES)
					fatal_error(" too many files");
				*addr_ptr++ = sym.st_value;
				if (debug)
					printf("__link found at 0x%x\n",
					       sym.st_value);
			}
		}
		else if (undr == 1 && strcmp(str, "main") == 0)
			found_main++;

	}

	if (!head) {
		if (found_main == 0)
			fatal_error("_main() not found");
		else
			fatal_error("Bad _main() loaded- libC probably not set up for patch");
	}

	/* Now we have all of the __link pointers.
	 * close the file, and reopen it for updating to
	 * write the patches.  All hell will break loose
	 * if someone writes the file in the meantime.
	 */
	elf_end( elf );
	close( fid );
	close( fid1 );

	/* If no symbols were found, quit*/
	if ( addr_ptr == addrs) {
		if(debug)
			printf("No __links found\n");
		exit(0);
	}

	if ( (fptr = fopen(file, "r+")) == NULL)
		fatal_error(" can't reopen file");

	/* patch the first symbol
	 * seek to: physical adr. of symbol
	 *  - physical adr of start of data
	 *  + file offset of start of data
	 */

	previous = head - data_pa + data_infile;

	/* Now, go thru the list of symbols. Each is
	 * a pointer to the next link. Chain them up.
	 *
	 * For non-obvious reasons, do this backwards.
	 * This calls ctors from libraries first.
	 */

	for (symbol = addr_ptr - 1; symbol >= addrs; symbol --) {
		/* Update the previous pointer to point to this one.*/
		if(debug)
			printf("Write 0x%x at offset 0x%x\n", *symbol, previous );

		if (fseek(fptr, previous , 0))
			fatal_error("can't seek");

		if( fwrite((char *)symbol, sizeof(Elf32_Addr), 1, fptr) == 0)
			fatal_error("can't write file");

		previous = *symbol - data_pa + data_infile;
	}

	/*Zero out the last symbol*/
	if(fseek(fptr, previous , 0))
		fatal_error("can't seek");

	if (fwrite((char *)&zero, sizeof(Elf32_Addr), 1, fptr) == 0)
		fatal_error("can't write");

	if(debug)
		printf("Write 0 at offset 0x%x\n", previous );

	fclose(fptr);

	exit(0);
}

void
fatal_error(message)
char * message;
{
	fprintf(stderr,"patch: file %s: %s\n", file, message);
	exit(-1);
}
	
int
ScnhRead( elf, strndx, sname, shead)
Elf* elf;
int  strndx;
char* sname;
Elf32_Shdr** shead;
{
	Elf_Scn	*scn = 0;
	int	idx = 0;

	while ((scn = elf_nextscn(elf, scn)) != 0) {
		idx++;
		if ((*shead = elf32_getshdr(scn)) != 0)
			if (strcmp(sname, elf_strptr(elf, strndx, (size_t)(*shead)->sh_name)) == 0)
				break;
	}

	return idx;
}
