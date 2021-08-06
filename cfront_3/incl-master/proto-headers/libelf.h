/*ident	"@(#)cls4:incl-master/proto-headers/libelf.h	1.1" */
#usedby svr4 solaris

/*******************************************************************************
 
C++ source for the C++ Language System, Release 3.0.  This product
is a new release of the original cfront developed in the computer
science research center of AT&T Bell Laboratories.

Copyright (c) 1991 AT&T and UNIX System Laboratories, Inc.
Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.

THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
Laboratories, Inc.  The copyright notice above does not evidence
any actual or intended publication of such source code.

*******************************************************************************/

#ifndef __LIBELF_H
#define __LIBELF_H

#hide	elf_begin
#hide	elf_cntl
#hide	elf_end	
#hide	elf_errmsg
#hide	elf_errno
#hide	elf_fill
#hide	elf_flagdata
#hide	elf_flagehdr
#hide	elf_flagelf
#hide	elf_flagphdr
#hide	elf_flagscn
#hide	elf_flagshdr
#hide	elf32_fsize
#hide	elf_getarhdr
#hide	elf_getarsym
#hide	elf_getbase
#hide	elf_getdata
#hide	elf32_getehdr
#hide	elf_getident
#hide	elf32_getphdr
#hide	elf_getscn
#hide	elf32_getshdr
#hide 	elf_hash
#hide	elf_kind
#hide	elf_ndxscn
#hide	elf_newdata
#hide	elf32_newehdr
#hide	elf32_newphdr
#hide	elf_newscn
#hide	elf_nextscn
#hide	elf_next
#hide	elf_rand
#hide	elf_rawdata
#hide	elf_rawfile
#hide	elf_strptr
#hide	elf_update
#hide	elf_version
#hide	elf32_xlatetof
#hide	elf32_xlatetom

#expand libelf.h

/*	function declarations
 */
extern "C" {
	Elf		*elf_begin	(int, Elf_Cmd, Elf *);
	int		elf_cntl	(Elf *, Elf_Cmd);
	int		elf_end		(Elf *);
	const char	*elf_errmsg	(int);
	int		elf_errno	(void);
	void		elf_fill	(int);
	unsigned	elf_flagdata	(Elf_Data *, Elf_Cmd, unsigned);
	unsigned	elf_flagehdr	(Elf *, Elf_Cmd,  unsigned);
	unsigned	elf_flagelf	(Elf *, Elf_Cmd, unsigned);
	unsigned	elf_flagphdr	(Elf *, Elf_Cmd, unsigned);
	unsigned	elf_flagscn	(Elf_Scn *, Elf_Cmd, unsigned);
	unsigned	elf_flagshdr	(Elf_Scn *, Elf_Cmd, unsigned);
	size_t		elf32_fsize	(Elf_Type, size_t, unsigned);
	Elf_Arhdr	*elf_getarhdr	(Elf *);
	Elf_Arsym	*elf_getarsym	(Elf *, size_t *);
	off_t		elf_getbase	(Elf *);
	Elf_Data	*elf_getdata	(Elf_Scn *, Elf_Data *);
	Elf32_Ehdr	*elf32_getehdr	(Elf *);
	char		*elf_getident	(Elf *, size_t *);
	Elf32_Phdr	*elf32_getphdr	(Elf *);
	Elf_Scn		*elf_getscn	(Elf *elf, size_t);
	Elf32_Shdr	*elf32_getshdr	(Elf_Scn *);
	unsigned long	elf_hash	(const char *);
	Elf_Kind	elf_kind	(Elf *);
	size_t		elf_ndxscn	(Elf_Scn *);
	Elf_Data	*elf_newdata	(Elf_Scn *);
	Elf32_Ehdr	*elf32_newehdr	(Elf *);
	Elf32_Phdr	*elf32_newphdr	(Elf *, size_t);
	Elf_Scn		*elf_newscn	(Elf *);
	Elf_Scn		*elf_nextscn	(Elf *, Elf_Scn *);
	Elf_Cmd		elf_next	(Elf *);
	size_t		elf_rand	(Elf *, size_t);
	Elf_Data	*elf_rawdata	(Elf_Scn *, Elf_Data *);
	char		*elf_rawfile	(Elf *, size_t *);
	char		*elf_strptr	(Elf *, size_t, size_t);
	off_t		elf_update	(Elf *, Elf_Cmd);
	unsigned	elf_version	(unsigned);
	Elf_Data	*elf32_xlatetof	(Elf_Data *, const Elf_Data *, unsigned);
	Elf_Data	*elf32_xlatetom	(Elf_Data *, const Elf_Data *, unsigned);

}

#endif
