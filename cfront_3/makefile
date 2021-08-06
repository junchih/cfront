#ident	"@(#)cls4:makefile	1.1"
###############################################################################
#
# C++ source for the C++ Language System, Release 3.0.  This product
# is a new release of the original cfront developed in the computer
# science research center of AT&T Bell Laboratories.
#
# Copyright (c) 1991 AT&T and UNIX System Laboratories, Inc.
# Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.
#
# THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
#	
# Laboratories, Inc.  The copyright notice above does not evidence
# any actual or intended publication of such source code.
#
###############################################################################
#Makefile for the CC translator
#Please see AT&T C++ Language System 3.0 Release Notes for more information
############################################################################
#For first make (bootstrap version from C files below the scratch directory):
#	make scratch
#Otherwise:
#	make - equivalent to "make munch"
#	make munch - make a munch version
#	make patch - make a patch version (System V or BSD only)
#Additional: when make is complete:
#	make sc3.0 - compiles L5 libraries
#	make libC_p.a - compiles libraries with -p for profiling
#	make sc3.0_p - compiles L5 libraries with -p for profiling
#	make demos - compiles and runs demo programs in demo
#	make demos++ - compiles and runs L5 demo programs 
#	make install - install the translator into common directories
#	make demotask - compiles and runs example task programs in demo/task
#       make democomplex- compiles and runs example complex programs in demo/complex
#       make clean - removes all .o files generated in these procedures
#       make clobber - removes all executables and libraries, cleans up .o's
############################################################################


# define the following variables by uncommenting the appropriate line.

# from the two below, pick the operating system closest to yours:
#SYS=SYSV
SYS=BSD

# This makefile can generate C++ header files for the following 
# operating systems.  Please pick the one closest to yours.

# svr2 is system V release 2
#OS=svr2
# svr3 is system V release 3
#OS=svr3
# svr4 is system V release 4
#OS=svr4
# A Starserver FT running svr4
#OS=svr4FT
# sun is for SunOS. If you choose sun the scripts will apply
# a heuristic to determine whether you're running os3, os4, or os4.1.
# To override the heuristic you may choose sunos3, 4, or 4.1 explicitly
#OS=sun
#OS=sunos3
#OS=sunos4
OS=sunos4.1
#OS=solaris
# hpux8.0 is for HP UX 8.0
#OS=hpux8.0
# hpux is for HP
#OS=hpux
# bsd2 is for BSD 4.2
#OS=bsd2
# bsd3 is for BSD 4.3
#OS=bsd3
# Amdahl running native uts environment
#OS=uts
# Silicon Grahpics running IRIX 4.0 or 5.0
#OS=sgi-svr4
# Pyramid running svr3 in att universe
#OS=pyramid

# location of the standard C include files on your machine:
STDINCL=/usr/include

# change this to a 1 if your system supports symbolic links
# and you want your C++ headers to use them.  Do NOT set this
# to 1 if OS=solaris or sgi-svr4.
SYMBOLICLINK=0

# set this option if your OS has vsprintf()
#VSPRINTF="-DVSPRINTF=vsprintf"

# your processor (for building task library):
MACH=sparc
#MACH=3b
#MACH=vax
#MACH=386
#68k is for Sun-2 or Sun-3
#MACH=68k
#MACH=uts
SPARCSUF=`if test "$(MACH)" = "sparc"; then echo "_SPARC"; else echo ""; fi`

# these directories are used for installation via "make install"
INSTALL_BIN	= /usr/bin
INSTALL_LIB	= /usr/lib
INSTALL_INC	= /usr/include/CC

# command used to move files to the installation directory
INSTALL	= cp

# command used to copy a directory tree of newly built header files
# from the incl-master directory to the top level 
# Note: -l option specifies hard links.  Remove if your filesystem
# does not allow hard links across directories.
CPIO	= cpio -pdlm
#CPIO	= ./cpio.sh -pdlm

# set AON to +a0 (default) or +a1
# +a0 produces classic C style declarations in the intermediate C code
# +a1 produces ANSI C style declarations in the intermediate C code
AON=+a0

# the CC command to use for building cfront
CC	= CC

# any special options to pass to CC
CCFLAGS	= -O -D$(SYS) -DLICENSE_MAN
# any special options to pass to cc
CFLAGS = -O -D$(OS)

# Set the following three variables when you are porting to another target
# machine by generating new intermediate C scratch files (calling fillscratch).

# Set FILLDEF to define any predefined strings we recognize for the target 
# machine. Set FILLUNDEF to undefine any predefined strings for the host.
# set FILLDEF=-D<predefined target> -D<predefined target> etc.
# and FILLUNDEF=-U<predefined host> etc.

FILLDEF= 
FILLUNDEF= 

# Also when generating scratch files for another target machine, set
# SZAL to the location of the results file from the target szal.c executable
# on the target. See the porting section of Release Notes for details
# set SZAL=<szal_output_file>

SZAL=

# you shouldn't have to change anything beyond this line
#######################################################

MPMACRO	= PATCH
MPDIR	= Patch
MPFILE	= patch

#Some systems don't predefine $(MAKE)
MAKE=make

#Force the use of the "normal" shell (i.e. disable csh)
SHELL=/bin/sh

is_bsd	= test $(SYS) = BSD
is_svr4 = test $(OS) = svr4 -o $(OS) = solaris

is_hp = test $(OS) = hpux8.0 -o $(OS) = hpux

BSDFLAG = `if $(is_bsd); then echo 1; else echo 0; fi`
NEWCC	= CCROOTDIR=`pwd` I=`pwd`/incl LIBRARY=`pwd`/libC.a `pwd`/CC
REALCC	=  `pwd`/CC

ENV	= SYS=$(SYS) OS=$(OS) MACH=$(MACH) \
		CCFLAGS="$(CCFLAGS)" AON=$(AON) \
		ROOT=`pwd` SZAL="$(SZAL)" SYMBOLICLINK=$(SYMBOLICLINK)

ROOT	= `pwd`

STDBINS	= cfront c++filt ptcomp ptlink ncsl ncsldiff
BINFILES = cfront c++filt ptcomp ptlink ncsl ncsldiff fscpp dem demangle g2++comp hier incl.sh publik
LIBS	= libC.a libtask.a libcomplex.a lib++.a libGA.a libGraph.a libfs.a libg2++.a hier2 incl2 publik2 fsipp

all:	munch

incl-master/incl:
	cd incl-master && \
	$(MAKE) STDINCL=$(STDINCL) OS=$(OS) \
		SYMBOLICLINK=$(SYMBOLICLINK) VERBOSE=0

incl:   incl-master/incl
	rm -rf incl.temp && mkdir incl.temp
	cd incl-master/incl && find . \( -type d -o -type f \) -print |$(CPIO) ../../incl.temp
	if test $(SYMBOLICLINK) -eq 1 ; then \
		ln -s $(STDINCL) incl.temp/cc ; \
	fi
	mv incl.temp incl

munch:	set_munch always
	$(MAKE) $(ENV) CC="$(CC)" NEWCC="$(NEWCC)" mk_cfront
	rm -f patch Patch/patch

set_munch:
	for i in makefile src/makefile lib/mk/makefile lib/mk_p/makefile; \
	do \
		sed	-e 's/^\(MPMACRO	= \).*/\1MUNCH/' \
			-e 's/^\(MPDIR	= \).*/\1Munch/' \
			-e 's/^\(MPFILE	= \).*/\1munch/' $$i >$$i.$$$$; \
		if cmp $$i.$$$$ $$i >/dev/null ;then \
			rm $$i.$$$$; \
		else \
			mv -f $$i.$$$$ $$i; \
		fi \
	done

patch:	set_patch always
	$(MAKE) $(ENV) CC="$(CC)" NEWCC="$(NEWCC)" mk_cfront
	rm -f munch Munch/munch

set_patch:
	for i in makefile src/makefile lib/mk/makefile lib/mk_p/makefile; \
	do \
		sed	-e 's/^\(MPMACRO	= \).*/\1PATCH/' \
			-e 's/^\(MPDIR	= \).*/\1Patch/' \
			-e 's/^\(MPFILE	= \).*/\1patch/' $$i >$$i.$$$$; \
		if cmp $$i.$$$$ $$i >/dev/null ;then \
			rm $$i.$$$$; \
		else \
			mv -f $$i.$$$$ $$i; \
		fi \
	done

mk_cfront:	incl $(SYS) $(MPDIR)/$(MPFILE) $(STDBINS)
	rm -f $(MPFILE); ln $(MPDIR)/$(MPFILE) .
	$(MAKE) INSTALL_BIN=`pwd` INSTALL_LIB=`pwd` \
		INSTALL_INC=`pwd`/incl move_CC
	$(MAKE) $(ENV) CC="$(NEWCC)" libC.a
	$(MAKE) -f makefileSC CCFLAGS="$(CCFLAGS)" BSD=$(BSDFLAG) CC="$(REALCC)" sc3.0

src/cfront: $(SYS) always
	cd src && \
	$(MAKE) CC=$(CC) CCFLAGS="$(CCFLAGS)"

cfront:	src/cfront
	rm -f cfront; ln src/cfront .
	
$(SYS):	# suppress "don't know how to make $(SYS)" error message

$(OS):	# suppress "don't know how to make $(OS)" error message

BSD:
	chmod 755 bsd.fix && ./bsd.fix

hpux8.0:
	cd scratch && chmod 555 hp.sed && ./hp.sed

hpux:
	cd scratch && chmod 555 hp.sed && ./hp.sed

uts:
	cd scratch && chmod 555 uts.sed && ./uts.sed
	

c++filt:	tools/demangler/c++filt
	rm -f c++filt; ln tools/demangler/c++filt .

ncsl:		tools/ncsl/ncsl
	rm -f ncsl; ln tools/ncsl/ncsl .

ncsldiff:	tools/ncsl/ncsldiff
	rm -f ncsldiff; ln tools/ncsl/ncsldiff .

ptcomp:		tools/pt/ptcomp
	rm -f ptcomp; ln tools/pt/ptcomp .

ptlink:		tools/pt/ptlink
	rm -f ptlink; ln tools/pt/ptlink .

Munch/munch:	Munch/munch.c
	if $(is_hp) ;then \
		mv Munch/_main.c Munch/_main.c.save; \
		mv Munch/dtors.c Munch/dtors.c.save; \
		cp Munch/_main_hpux.c Munch/_main.c; \
		cp Munch/dtors_hpux.c Munch/dtors.c; \
	fi
	$(CC) $(CCFLAGS) -o Munch/munch Munch/munch.c
	rm -f munch.o

Patch/patch:	Patch/patch.c Patch/BSDpatch.c Patch/SVR4patch.c
	if $(is_svr4) ;then \
		cc -o Patch/patch -O Patch/SVR4patch.c -lelf; \
	elif $(is_bsd) ;then \
		cc -o Patch/patch -O Patch/BSDpatch.c; \
	else \
		cc -o Patch/patch -O Patch/patch.c -lld; \
	fi

lib/mk/libC.a: always
	cd lib/mk && \
	$(MAKE) CC="$(CC)" CCFLAGS="$(CCFLAGS) $(VSPRINTF)" $(SYS)=1

libC.a:	lib/mk/libC.a
	rm -f libC.a; ln lib/mk/libC.a .
	if $(is_bsd) ; then ranlib libC.a; fi

lib/mk_p/libC_p.a: always
	cd lib/mk_p && \
	$(MAKE) CC="$(CC)" CCFLAGS="$(CCFLAGS) $(VSPRINTF)" $(SYS)=1

libC_p.a:	lib/mk_p/libC_p.a
	rm -f libC_p.a; ln lib/mk_p/libC_p.a .
	if $(is_bsd) ; then ranlib libC_p.a; fi

sc3.0:	always
	$(MAKE) -f makefileSC CCFLAGS="$(CCFLAGS)" BSD=$(BSDFLAG) CC="$(REALCC)" sc3.0
	
sc3.0_p:	always
	$(MAKE) -f makefileSC CCFLAGS="$(CCFLAGS)" BSD=$(BSDFLAG) CC="$(REALCC)" sc3.0_p
	
tools/demangler/c++filt:	always
	cd tools/demangler && $(MAKE) CFLAGS="$(CFLAGS)" $(SYS)=1 c++filt

tools/ncsl/ncsl:		always
	cd tools/ncsl && $(MAKE) CFLAGS="$(CFLAGS)" $(SYS)=1 ncsl 

tools/ncsl/ncsldiff:		always
	cd tools/ncsl && $(MAKE) CFLAGS="$(CFLAGS)" $(SYS)=1 ncsldiff

tools/pt/ptcomp:		always
	cd tools/pt && $(MAKE) CFLAGS="$(CFLAGS)" $(SYS)=1 ptcomp 

tools/pt/ptlink:		always
	cd tools/pt ; $(MAKE) CFLAGS="$(CFLAGS)" $(SYS)=1 ptlink ; chmod +x tool1 tool2

lib/complex/mk/libcomplex.a:	always
	cd lib/complex/mk && \
	$(MAKE) CC="$(CC)" CCFLAGS="$(CCFLAGS)" $(SYS)=1

libcomplex.a:	lib/complex/mk/libcomplex.a
	rm -f libcomplex.a; ln lib/complex/mk/libcomplex.a .
	if $(is_bsd) ; then ranlib libcomplex.a; fi

libtask.a:	always
# bogus exit -1 to stop make if illegal machine
	if test ! "$(MACH)" ; then\
		echo make: syntax: make MACH=\<machine\> libtask.a;\
		echo "\twhere MACH is one of: 3b, vax, 386, 68k, uts, sparc";\
		exit -1;\
	else \
		case "$(MACH)" in \
		vax|386|68k|3b|uts)	chmod +w lib/task/task/swap.s.$(MACH) \
					 lib/task/task/fudge.c.$(MACH) \
			;; \
		sparc) : \
			;; \
		*) echo make: MACH: $(MACH): unknown machine; \
		   echo "\tMACH is one of: 3b, vax, 386, 68k, uts";\
		   exit -1\
		   ;; \
		esac; \
	fi
	cd lib/task$(SPARCSUF)/mk && \
	$(MAKE) CC="$(CC)" CCFLAGS="$(CCFLAGS)" $(SYS)=1 MACH=$(MACH)
	rm -f libtask.a; ln lib/task$(SPARCSUF)/mk/libtask.a .
	if $(is_bsd) ; then ranlib libtask.a; fi

demotask: libtask.a
	cd demo/task; chmod 755 runtests; $(MAKE) CC="$(CC)" CCFLAGS="$(CCFLAGS)" $(SYS)=1 run

democomplex: libcomplex.a
	cd demo/complex; chmod 755 runtests; $(MAKE) CC="$(CC)" CCFLAGS="$(CCFLAGS)" $(SYS)=1 run

scratch: clean $(SYS) $(OS) incl c++filt ptcomp ptlink set_munch CC always
	cd scratch && $(MAKE) $(SYS)=1
	$(MAKE) INSTALL_BIN=`pwd` INSTALL_LIB=`pwd` \
		INSTALL_INC=`pwd`/incl move_CC
	echo 'Now do a "make CC='`pwd`'/CC munch" or "make CC='`pwd`'/CC patch"'

clean:	
	rm -f *.o a.out core
	rm -f scratch/*..o
	rm -fr lib/mk/*.o  lib/mk/libC.a
	rm -fr lib/mk_p/*.o  lib/mk_p/libC_p.a
	rm -fr lib/complex/mk/*.o lib/complex/mk/libcomplex.a
	rm -fr lib/task/mk/*.o  lib/task/mk/libtask.a
	rm -fr lib/task/task/swap.s lib/task/task/fudge.c
	cd src && $(MAKE) clean
	rm -fr demo/task/*.[oE]
	rm -fr demo/complex/*.[oE]
	rm -fr demo/stream/*.[oE]
	rm -fr demo/lang/*.[oE]
	rm -fr demo/generic/*.[oE]
	rm -f Munch/munch
	rm -f Patch/patch
	rm -fr incl.temp 
	cd incl-master && $(MAKE) clean
	rm -f src/cfront
	rm -f tools/demangler/c++filt
	rm -f tools/ncsl/ncsl
	rm -f tools/ncsl/ncsldiff
	rm -f tools/pt/ptcomp
	rm -f tools/pt/ptlink
	cd tools/demangler && $(MAKE) clean
	cd tools/pt && $(MAKE) clean
	$(MAKE) -f makefileSC CCFLAGS="$(CCFLAGS)" BSD="$(BSDFLAG)" CC="$(REALCC)" clean

clobber: clean
	if test $(INSTALL_BIN) != `pwd` ;then \
		rm -fr cfront patch munch c++filt ptcomp ptlink; \
	fi
	if test $(INSTALL_LIB) != `pwd` ;then \
		rm -fr libC.a libcomplex.a libtask.a; \
	fi
	rm -fr incl
	cd incl-master && $(MAKE) clobber
	cd tools/demangler && $(MAKE) clobber

demos:
	cd demo/lang; chmod 755 runtests; $(MAKE) CC="$(CC)" CCFLAGS="$(CCFLAGS)"
	$(MAKE) -f makefileSC CC="$(REALCC)" BSD=$(BSDFLAG) CCFLAGS="$(CCFLAGS)" demos
demos++:
	$(MAKE) -f makefileSC CC="$(REALCC)" BSD=$(BSDFLAG) CCFLAGS="$(CCFLAGS)" demos

#This target will populate the scratch directories with good-old-c
#files.  This is used to port to another machine.
#Set SZAL, FILLDEF and FILLUNDEF above before using fillscratch

fillscratch:	set_munch
	if test ! -d scratch/mnch; then mkdir scratch/mnch; fi
	SZAL='SZAL='; \
	case "$(SZAL)" in \
	'')	szal=''; SZAL='';; \
	+x*)	szal="$(SZAL)";; \
	/*)	szal="+x$(SZAL)";; \
	*)	szal="+x../../$(SZAL)";; \
	esac; \
	(cd scratch/src && $(MAKE) CC=$(CC) FILLDEF="$(FILLDEF)" FILLUNDEF="$(FILLUNDEF)" $$SZAL$$szal) && \
	cd scratch/lib && $(MAKE) CC=$(CC) FILLDEF="$(FILLDEF)" FILLUNDEF="$(FILLUNDEF)" $$SZAL$$szal
	mv scratch/lib/munch..c scratch/mnch/munch..c
	chmod +x CC scratch/bsd.sed bsd.fix

install:	always
	if test $(INSTALL_LIB) != `pwd` ;then \
		test -d $(INSTALL_LIB) || mkdir $(INSTALL_LIB); \
		for i in $(LIBS); \
		do \
			if test -f $$i ;then \
				$(INSTALL) $$i $(INSTALL_LIB); \
				if $(is_bsd) ;then \
					ranlib $(INSTALL_LIB)/$$i; \
				fi; \
			fi; \
		done; \
	fi
	if test $(INSTALL_INC) != `pwd`/incl ;then \
		test -d $(INSTALL_INC)     || mkdir $(INSTALL_INC); \
		cd incl; \
		if test $(SYMBOLICLINK) -eq 1 ; then \
			find . -name cc -o -print | $(CPIO) $(INSTALL_INC); \
		else \
			find . -print | $(CPIO) $(INSTALL_INC); \
		fi; \
		if test $(SYMBOLICLINK) -eq 1 ; then \
			ln -s $(STDINCL) $(INSTALL_INC)/cc; \
		fi; \
		cd ..; \
		rm -f $(INSTALL_INC)/cpio.sh; \
	fi
	if test $(INSTALL_BIN) != `pwd` ;then \
		test -d $(INSTALL_BIN) || mkdir $(INSTALL_BIN); \
		if test -r patch ; then \
			$(INSTALL) patch $(INSTALL_BIN); \
		else \
			$(INSTALL) munch $(INSTALL_BIN); \
		fi; \
		for i in $(BINFILES); \
		do \
			if test -f $$i ;then \
				$(INSTALL) $$i $(INSTALL_BIN); \
			fi; \
		done; \
	fi
	$(MAKE) INSTALL_BIN=$(INSTALL_BIN) \
		INSTALL_LIB=$(INSTALL_LIB) \
		INSTALL_INC=$(INSTALL_INC) \
		AON=$(AON) move_CC

move_CC:
	sed	-e 's/^\(PM_FLAG=\).*/\1$(MPMACRO)/' \
		-e 's/^\(SYS=\).*/\1-D$(SYS)/' \
		-e 's;^\(CCROOTDIR=[^-]*-\).*;\1$(INSTALL_BIN)};' \
		-e 's;^\(CCLIBDIR=[^-]*-\).*;\1$(INSTALL_LIB)};' \
		-e 's;^\(I=[^-]*-\).*;\1$(INSTALL_INC)};' \
		-e 's;^\(AON=[^-]*-\).*;\1$(AON)};' \
			CC >$(INSTALL_BIN)/CC.$$$$; \
	mv -f $(INSTALL_BIN)/CC.$$$$ $(INSTALL_BIN)/CC
	chmod +x $(INSTALL_BIN)/CC

always:	
