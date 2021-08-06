#makefile for compiling and running task tests
#
#This makefile is perhaps more complicated than might seem necessary
#in order to run all tests in 4 configurations.  Because optimization
#often has a great effect on the task library, it is sometimes worth
#building 2 versions of the library, one optimized (libtaskO.a) and
#one built with -g (libtask.a).  This makefile will (if you want) build
#each test with -g and -O, and link each of those with each of the 2
#libraries, yielding 4 executables for each test.  (NOTE:  this takes
#up a lot of space!)  You can also build and run just one version of
#each test if you want.  See the list of targets, below.

#The naming conventions for the 4 configurations are these:
#	test name	library name		compilation flags	code
#	test.E		libtask.a		$CCFLAGSG		gg
#	testgO.E	libtask.a		$CCFLAGS		go
#	testO.E		libtaskO.a		$CCFLAGSG		og
#	testOO.E	libtaskO.a		$CCFLAGS		oo
#That is, this makefile builds each test with the CC options shown under
#compilation flags and links with the library shown under library name.
#By convention, libtask.a is built with -g, libtaskO.a is built with -O.
#However, if you're only testing a task lib built with -O, name it libtask.a
#and use "make rungg" or "make compilegg" to build one version of each test.
#To use libtaskO.a, you will need to set P=O on the make command line;
#see under targets, below.
#
#A fifth variant of the tests is to use a SHARED-only version of the
#task library, called libtaskSH.a.  If you have a SHARED-only version
#of the library to test, set SH=SH on the make command line.
#
#A script called runtests is used to run the executables and compare
#them with a .V (verification) file.  It prints "passed" or "failed"
#for each test, depending on whether the output matches the expected
#output in the .V file.  runtests takes testfile base names (that is,
#names with no suffix, no .C or .E or .V) as arguments.  It also takes
#options -gg, -go, -og, and -oo to determine which test configuration
#to run.  Finally, it can be run with the -DEBUG option, which will
#print the differences between the .V file and the test output, if any.
#
# make targets:
#	make run	Compiles and runs all tests in all 4
#			-O/-g configurations.  NOTE:  You must set P=O on make
#			command line to use this target:  make P=O run.
#	make rungg	Compiles and runs all tests in gg configuration only;
#			ie, uses libtask.a and $CCFLAGSG
#	make runOO	Compiles and runs all tests in oo configuration only;
#			ie, uses libtaskO.a and $CCFLAGS.  NOTE:You need to
#			set P=O on the make command line to use this target.
#			eg, make P=O runOO
#	make rung	Compiles and runs all tests in gg and go configurations;
#			ie, uses libtask.a and both $CCFLAGSG and $CCFLAGS
#	make runO	Compiles and runs all tests in oo and og configurations;
#			ie, uses libtaskO.a and both $CCFLAGSG and $CCFLAGS.
#			NOTE:  You need to set P=O on the make command line to
#			use this target, eg, make P=O runO.
#	make runSH	Compiles and runs all tests using libtaskSH.a, the 
#			SHARED-only version of the library.  You need to set
#			SH=SH (or SH=some-suffix-to-libtask) on the make
#			command line to use this one.

# The compile targets below correspond to the run targets above, but they
# do not run the tests.
#	make compile
#	make compileO
#	make compileg
#	make compileSH
#	You can also make any test individually, eg:  make triv.E

#	make Vfiles file-base-names	Builds .V files for the named tests.
#					Use this for new tests when you are
#					sure the output is correct.

CC=CC
CCFLAGS=-O -I.
CCFLAGSG=-I. 
LPFLAGS=-ql
PRFLAGS=-qp
XPFLAGS=-qx

#I should be set to the directory where the task.h being tested is
#I=/usr/include/CC
I=../task
IFLAGS=-I$(I)

#L should be set to the directory where the libtask.a is
L=../mk
#L=/usr/lib

#LOPT=-Wl,-L$(L)
LOPT=-L$(L)
SH=

LFLAGS=-ltask$(SH)
#This one is for use testing the unbundled C++ library package.
#LFLAGS=-ltask$(SH) -lstd


ALL = $(ALLGG) $(ALLGO) $(ALLOG) $(ALLOO)
#echo "lib compiled -g; test compiled without optim: test.E"
ALLGG = triv.E nontriv.E regtest.E shared.E shareg.E sh-ded.E ded-sh.E sh-noded.E sh-ded-rec.E exit_stat.E alph.E sigtest.E t_switch.E t_create.E sigq.E trivrand.E triverand.E Spaces.E Qex1.E Qex2.E Qex3.E filter.E filter2.E compat.E misc.E sh_misc.E public.E splice.E mi.E delTERM.E delTERM2.E 2cancel.E
#echo "lib compiled -g; test compiled -O:  testgO.E"
ALLGO = trivgO.E nontrivgO.E regtestgO.E sharedgO.E shareggO.E sh-dedgO.E ded-shgO.E sh-nodedgO.E sh-ded-recgO.E exit_statgO.E  alphgO.E sigtestgO.E t_switchgO.E t_creategO.E sigqgO.E trivrandgO.E triverandgO.E SpacesgO.E Qex1gO.E Qex2gO.E Qex3gO.E filtergO.E filter2gO.E compatgO.E miscgO.E sh_miscgO.E publicgO.E splicegO.E migO.E delTERMgO.E delTERM2gO.E 2cancelgO.E
#echo "lib compiled -O; test compiled without optim: testO.E"
ALLOG = trivO.E nontrivO.E regtestO.E sharedO.E sharegO.E sh-dedO.E ded-shO.E sh-nodedO.E sh-ded-recO.E exit_statO.E alphO.E sigtestO.E t_switchO.E t_createO.E sigqO.E trivrandO.E triverandO.E SpacesO.E Qex1O.E Qex2O.E Qex3O.E filterO.E filter2O.E compatO.E miscO.E sh_miscO.E publicO.E spliceO.E miO.E delTERMO.E delTERM2O.E 2cancelO.E
#echo "lib compiled -O; test compiled -O:  testOO.E"
ALLOO = trivOO.E nontrivOO.E regtestOO.E sharedOO.E sharegOO.E sh-dedOO.E ded-shOO.E sh-nodedOO.E sh-ded-recOO.E exit_statOO.E alphOO.E sigtestOO.E t_switchOO.E t_createOO.E sigqOO.E trivrandOO.E triverandOO.E SpacesOO.E Qex1OO.E Qex2OO.E Qex3OO.E filterOO.E filter2OO.E compatOO.E miscOO.E sh_miscOO.E publicOO.E spliceOO.E miOO.E delTERMOO.E delTERM2OO.E 2cancelOO.E
ALLSH = $(SH)triv.E $(SH)nontriv.E $(SH)regtest.E $(SH)shared.E $(SH)shareg.E $$(SH)sh-ded $(SH)ded-sh $(SH)sh-noded $(SH)sh-ded-rec (SH)exit_stat.E $(SH)alph.E $(SH)sigtest.E $(SH)t_switch.E $(SH)t_create.E $(SH)sigq.E $(SH)trivrand.E $(SH)triverand.E $(SH)Spaces.E $(SH)Qex1.E $(SH)Qex2.E $(SH)Qex3.E $(SH)filter.E $(SH)filter2.E $(SH)compat.E $(SH)misc.E $(SH)sh_misc.E $(SH)public.E $(SH)splice.E $(SH)mi.E $(SH)delTERM.E $(SH)delTERM2.E $(SH)2cancel.E
NAMES = $(NAMESGG) $(NAMESGO) $(NAMESOG) $(NAMESOO)
NAMESGG = triv nontriv regtest shared shareg sh-ded ded-sh sh-noded sh-ded-rec exit_stat alph sigtest trivrand triverand Spaces Qex1 Qex2 Qex3 filter filter2 compat misc sh_misc public splice mi delTERM delTERM2 2cancel
NAMESGO = trivGO nontrivGO regtestGO sharedGO sharegGO sh-dedGO ded-shGO sh-nodedGO sh-ded-recGO exit_statGO alphGO sigtestGO trivrandGO triverandGO SpacesGO Qex1GO Qex2GO Qex3GO filterGO filter2GO compatGO miscGO sh_miscGO publicGO spliceGO miGO delTERMGO delTERM2GO 2cancelGO
NAMESOG = trivOG nontrivOG regtestOG sharedOG sharegOG sh-dedOG ded-shOG sh-nodedOG sh-ded-recOG exit_statOG alphOG sigtestOG trivrandOG triverandOG SpacesOG Qex1OG Qex2OG Qex3OG filterOG filter2OG compatOG miscOG sh_miscOG publicOG spliceOG miOG delTERMOG delTERM2OG 2cancelOG
NAMESOO = trivOO nontrivOO regtestOO sharedOO sharegOO sh-dedOO ded-shOO sh-nodedOO sh-ded-recOO exit_statOO alphOO sigtestOO trivrandOO triverandOO SpacesOO Qex1OO Qex2OO Qex3OO filterOO filter2OO compatOO miscOO sh_miscOO publicOO spliceOO miOO delTERMOO delTERM2OO 2cancelOO
NAMESSH = SHtriv SHnontriv SHregtest SHshared SHshareg SHsh-ded SHded-sh SHsh-noded SHsh-ded-rec SHexit_stat SHalph SHsigtest SHtrivrand SHtriverand SHSpaces SHQex1 SHQex2 SHQex3 SHfilter SHfilter2 SHcompat SHmisc SHsh_misc SHpublic SHsplice SHmi SHdelTERM SHdelTERM2 SH2cancel

compile: $(ALL)
compileO: $(ALLOO)
compileg: $(ALLGG)
compileSH: $(ALLSH)

#SAK:  make compileg complains about libtaskO.a and libtaskSH.a not being
#      around when it shouldn't care about them.
#SAK:  ??  $(ALL): $(L)/libtask.a $(L)/libtaskO.a
$(ALL): $(L)/libtask.a

#SAK:  $(ALLOO): $(L)/libtaskO.a
$(ALLGG): $(L)/libtask.a
#SAK:  $(ALLSH): $(L)/libtaskSH.a

Vfiles: $(ALLGG)
	chmod +x makeVfiles
	makeVfiles $(NAMESGG)

run: $(ALL)
	chmod +x runtests
	BSD=$(BSD) runtests -gg -go -og -oo $(NAMESGG)
test: 
	chmod +x runtests
	BSD=$(BSD) runtests -gg $(NAMESGG)
runO: $(ALLOO) $(ALLOG)
	chmod +x runtests
	BSD=$(BSD) runtests -og -oo $(NAMESGG)
rung: $(ALLGG) $(ALLGO)
	chmod +x runtests
	BSD=$(BSD) runtests -gg -go $(NAMESGG)
rungg: $(ALLGG)
	chmod +x runtests
	BSD=$(BSD) runtests -gg $(NAMESGG)
runOO: $(ALLOO)
	chmod +x runtests
	BSD=$(BSD) runtests -oo $(NAMESGG)
runSH: $(ALLSH)
	chmod +x runtests
	BSD=$(BSD) runtests -SH $(NAMESGG)

$(SH)triv.E: triv.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)triv.E  triv.C $(LOPT) $(LFLAGS)

$(SH)nontriv.E: nontriv.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)nontriv.E  nontriv.C $(LOPT) $(LFLAGS)

$(SH)regtest.E: regtest.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)regtest.E  regtest.C $(LOPT) $(LFLAGS)

$(SH)shared.E: shared.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)shared.E  shared.C $(LOPT) $(LFLAGS)

$(SH)shareg.E: shareg.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)shareg.E  shareg.C $(LOPT) $(LFLAGS)

$(SH)sh-ded.E: sh-ded.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)sh-ded.E  sh-ded.C $(LOPT) $(LFLAGS)

$(SH)ded-sh.E: ded-sh.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)ded-sh.E  ded-sh.C $(LOPT) $(LFLAGS)

$(SH)sh-noded.E: sh-noded.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)sh-noded.E  sh-noded.C $(LOPT) $(LFLAGS)

$(SH)sh-ded-rec.E: sh-ded-rec.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)sh-ded-rec.E  sh-ded-rec.C $(LOPT) $(LFLAGS)

$(SH)exit_stat.E: exit_stat.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)exit_stat.E  exit_stat.C $(LOPT) $(LFLAGS)

$(SH)alph.E: alph.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)alph.E  alph.C $(LOPT) $(LFLAGS)

$(SH)sigtest.E: sigtest.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)sigtest.E  sigtest.C $(LOPT) $(LFLAGS)

$(SH)t_create.E: t_create.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)t_create.E  t_create.C $(LOPT) $(LFLAGS)

$(SH)t_switch.E: t_switch.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)t_switch.E  t_switch.C $(LOPT) $(LFLAGS)

$(SH)sigq.E: sigq.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)sigq.E  sigq.C $(LOPT) $(LFLAGS)

$(SH)trivrand.E: trivrand.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)trivrand.E  trivrand.C $(LOPT) $(LFLAGS)

$(SH)triverand.E: triverand.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)triverand.E  triverand.C $(LOPT) $(LFLAGS) -lm

$(SH)Spaces.E: Spaces.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)Spaces.E  Spaces.C $(LOPT) $(LFLAGS)

$(SH)Qex1.E: Qex1.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)Qex1.E  Qex1.C $(LOPT) $(LFLAGS)

$(SH)Qex2.E: Qex2.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)Qex2.E  Qex2.C $(LOPT) $(LFLAGS)

$(SH)Qex3.E: Qex3.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)Qex3.E  Qex3.C $(LOPT) $(LFLAGS)

$(SH)filter.E: filter.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)filter.E  filter.C $(LOPT) $(LFLAGS)

$(SH)filter2.E: filter2.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)filter2.E  filter2.C $(LOPT) $(LFLAGS)

$(SH)compat.E: compat.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)compat.E  compat.C $(LOPT) $(LFLAGS)

$(SH)misc.E: misc.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)misc.E  misc.C $(LOPT) $(LFLAGS)

$(SH)sh_misc.E: sh_misc.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)sh_misc.E  sh_misc.C $(LOPT) $(LFLAGS)

$(SH)public.E: public.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)public.E  public.C $(LOPT) $(LFLAGS)

$(SH)splice.E: splice.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)splice.E  splice.C $(LOPT) $(LFLAGS)

$(SH)mi.E: mi.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)mi.E  mi.C $(LOPT) $(LFLAGS)

$(SH)delTERM.E: delTERM.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)delTERM.E  delTERM.C $(LOPT) $(LFLAGS)

$(SH)delTERM2.E: delTERM2.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)delTERM2.E  delTERM2.C $(LOPT) $(LFLAGS)

$(SH)2cancel.E: 2cancel.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o $(SH)2cancel.E  2cancel.C $(LOPT) $(LFLAGS)


trivgO.E: triv.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o trivgO.E  triv.C $(LOPT) -ltask

nontrivgO.E: nontriv.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o nontrivgO.E  nontriv.C $(LOPT) -ltask

regtestgO.E: regtest.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o regtestgO.E  regtest.C $(LOPT) -ltask

sharedgO.E: shared.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o sharedgO.E  shared.C $(LOPT) -ltask

shareggO.E: shareg.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o shareggO.E  shareg.C $(LOPT) -ltask

sh-dedgO.E: sh-ded.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o sh-dedgO.E  sh-ded.C $(LOPT) -ltask

ded-shgO.E: ded-sh.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o ded-shgO.E  ded-sh.C $(LOPT) -ltask

sh-nodedgO.E: sh-noded.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o sh-nodedgO.E  sh-noded.C $(LOPT) -ltask

sh-ded-recgO.E: sh-ded-rec.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o sh-ded-recgO.E  sh-ded-rec.C $(LOPT) -ltask

exit_statgO.E: exit_stat.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o exit_statgO.E  exit_stat.C $(LOPT) -ltask

alphgO.E: alph.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o alphgO.E  alph.C $(LOPT) -ltask

sigtestgO.E: sigtest.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o sigtestgO.E  sigtest.C $(LOPT) -ltask

t_creategO.E: t_create.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o t_creategO.E  t_create.C $(LOPT) -ltask

t_switchgO.E: t_switch.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o t_switchgO.E  t_switch.C $(LOPT) -ltask

sigqgO.E: sigq.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o sigqgO.E  sigq.C $(LOPT) -ltask

trivrandgO.E: trivrand.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o trivrandgO.E  trivrand.C $(LOPT) -ltask

triverandgO.E: triverand.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o triverandgO.E  triverand.C $(LOPT) -ltask -lm

SpacesgO.E: Spaces.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o SpacesgO.E  Spaces.C $(LOPT) -ltask

Qex1gO.E: Qex1.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o Qex1gO.E  Qex1.C $(LOPT) -ltask

Qex2gO.E: Qex2.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o Qex2gO.E  Qex2.C $(LOPT) -ltask

Qex3gO.E: Qex3.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o Qex3gO.E  Qex3.C $(LOPT) -ltask

filtergO.E: filter.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o filtergO.E  filter.C $(LOPT) -ltask

filter2gO.E: filter2.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o filter2gO.E  filter2.C $(LOPT) -ltask

compatgO.E: compat.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o compatgO.E  compat.C $(LOPT) -ltask

miscgO.E: misc.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o miscgO.E  misc.C $(LOPT) -ltask

sh_miscgO.E: sh_misc.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o sh_miscgO.E  sh_misc.C $(LOPT) -ltask

publicgO.E: public.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o publicgO.E  public.C $(LOPT) -ltask

splicegO.E: splice.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o splicegO.E  splice.C $(LOPT) -ltask

migO.E: mi.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o migO.E  mi.C $(LOPT) -ltask

delTERMgO.E: delTERM.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o delTERMgO.E  delTERM.C $(LOPT) -ltask

delTERM2gO.E: delTERM2.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o delTERM2gO.E  delTERM2.C $(LOPT) -ltask

2cancelgO.E: 2cancel.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o 2cancelgO.E  2cancel.C $(LOPT) -ltask


trivO.E: triv.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o trivO.E  triv.C $(LOPT) -ltaskO

nontrivO.E: nontriv.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o nontrivO.E  nontriv.C $(LOPT) -ltaskO

regtestO.E: regtest.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o regtestO.E  regtest.C $(LOPT) -ltaskO

sharedO.E: shared.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o sharedO.E  shared.C $(LOPT) -ltaskO

sharegO.E: shareg.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o sharegO.E  shareg.C $(LOPT) -ltaskO

sh-dedO.E: sh-ded.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o sh-dedO.E  sh-ded.C $(LOPT) -ltask

ded-shO.E: ded-sh.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o ded-shO.E  ded-sh.C $(LOPT) -ltask

sh-nodedO.E: sh-noded.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o sh-nodedO.E  sh-noded.C $(LOPT) -ltask

sh-ded-recO.E: sh-ded-rec.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o sh-ded-recO.E  sh-ded-rec.C $(LOPT) -ltask

exit_statO.E: exit_stat.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o exit_statO.E  exit_stat.C $(LOPT) -ltaskO

alphO.E: alph.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o alphO.E  alph.C $(LOPT) -ltaskO

sigtestO.E: sigtest.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o sigtestO.E  sigtest.C $(LOPT) -ltaskO

t_createO.E: t_create.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o t_createO.E  t_create.C $(LOPT) -ltaskO

t_switchO.E: t_switch.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o t_switchO.E  t_switch.C $(LOPT) -ltaskO

sigqO.E: sigq.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o sigqO.E  sigq.C $(LOPT) -ltaskO

trivrandO.E: trivrand.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o trivrandO.E  trivrand.C $(LOPT) -ltaskO

triverandO.E: triverand.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o triverandO.E  triverand.C $(LOPT) -ltaskO -lm

SpacesO.E: Spaces.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o SpacesO.E  Spaces.C $(LOPT) -ltaskO

Qex1O.E: Qex1.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o Qex1O.E  Qex1.C $(LOPT) -ltaskO

Qex2O.E: Qex2.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o Qex2O.E  Qex2.C $(LOPT) -ltaskO

Qex3O.E: Qex3.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o Qex3O.E  Qex3.C $(LOPT) -ltaskO

filterO.E: filter.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o filterO.E  filter.C $(LOPT) -ltaskO

filter2O.E: filter2.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o filter2O.E  filter2.C $(LOPT) -ltaskO

compatO.E: compat.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o compatO.E  compat.C $(LOPT) -ltaskO

miscO.E: misc.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o miscO.E  misc.C $(LOPT) -ltaskO

sh_miscO.E: sh_misc.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o sh_miscO.E  sh_misc.C $(LOPT) -ltaskO

publicO.E: public.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o publicO.E  public.C $(LOPT) -ltaskO

spliceO.E: splice.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o spliceO.E  splice.C $(LOPT) -ltaskO

miO.E: mi.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o miO.E  mi.C $(LOPT) -ltaskO

delTERMO.E: delTERM.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o delTERMO.E  delTERM.C $(LOPT) -ltaskO

delTERM2O.E: delTERM2.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o delTERM2O.E  delTERM2.C $(LOPT) -ltaskO

2cancelO.E: 2cancel.C
	$(CC) $(CCFLAGSG) $(IFLAGS) -o 2cancelO.E  2cancel.C $(LOPT) -ltaskO


trivOO.E: triv.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o trivOO.E  triv.C $(LOPT) -ltaskO

nontrivOO.E: nontriv.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o nontrivOO.E  nontriv.C $(LOPT) -ltaskO

regtestOO.E: regtest.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o regtestOO.E  regtest.C $(LOPT) -ltaskO

sharedOO.E: shared.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o sharedOO.E  shared.C $(LOPT) -ltaskO

sharegOO.E: shareg.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o sharegOO.E  shareg.C $(LOPT) -ltaskO

sh-dedOO.E: sh-ded.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o sh-dedOO.E  sh-ded.C $(LOPT) -ltask

ded-shOO.E: ded-sh.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o ded-shOO.E  ded-sh.C $(LOPT) -ltask

sh-nodedOO.E: sh-noded.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o sh-nodedOO.E  sh-noded.C $(LOPT) -ltask

sh-ded-recOO.E: sh-ded-rec.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o sh-ded-recOO.E  sh-ded-rec.C $(LOPT) -ltask

exit_statOO.E: exit_stat.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o exit_statOO.E  exit_stat.C $(LOPT) -ltaskO

alphOO.E: alph.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o alphOO.E  alph.C $(LOPT) -ltaskO

sigtestOO.E: sigtest.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o sigtestOO.E  sigtest.C $(LOPT) -ltaskO

t_createOO.E: t_create.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o t_createOO.E  t_create.C $(LOPT) -ltaskO

t_switchOO.E: t_switch.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o t_switchOO.E  t_switch.C $(LOPT) -ltaskO

sigqOO.E: sigq.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o sigqOO.E  sigq.C $(LOPT) -ltaskO

trivrandOO.E: trivrand.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o trivrandOO.E  trivrand.C $(LOPT) -ltaskO

triverandOO.E: triverand.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o triverandOO.E  triverand.C $(LOPT) -ltaskO -lm

SpacesOO.E: Spaces.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o SpacesOO.E  Spaces.C $(LOPT) -ltaskO

Qex1OO.E: Qex1.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o Qex1OO.E  Qex1.C $(LOPT) -ltaskO

Qex2OO.E: Qex2.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o Qex2OO.E  Qex2.C $(LOPT) -ltaskO

Qex3OO.E: Qex3.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o Qex3OO.E  Qex3.C $(LOPT) -ltaskO

filterOO.E: filter.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o filterOO.E  filter.C $(LOPT) -ltaskO

filter2OO.E: filter2.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o filter2OO.E  filter2.C $(LOPT) -ltaskO

compatOO.E: compat.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o compatOO.E  compat.C $(LOPT) -ltaskO

miscOO.E: misc.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o miscOO.E  misc.C $(LOPT) -ltaskO

sh_miscOO.E: sh_misc.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o sh_miscOO.E  sh_misc.C $(LOPT) -ltaskO

publicOO.E: public.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o publicOO.E  public.C $(LOPT) -ltaskO

spliceOO.E: splice.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o spliceOO.E  splice.C $(LOPT) -ltaskO

miOO.E: mi.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o miOO.E  mi.C $(LOPT) -ltaskO

delTERMOO.E: delTERM.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o delTERMOO.E  delTERM.C $(LOPT) -ltaskO

delTERM2OO.E: delTERM2.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o delTERM2OO.E  delTERM2.C $(LOPT) -ltaskO

2cancelOO.E: 2cancel.C
	$(CC) $(CCFLAGS) $(IFLAGS) -o 2cancelOO.E  2cancel.C $(LOPT) -ltaskO

clean:
	rm -f *.o

clobber: clean
	rm -f *..c
	rm -f $(ALL)
