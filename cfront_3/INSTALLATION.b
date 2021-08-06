Subject: C++ 3.0.3 executable installation letter

Dear 3.0.3 C++ Customer-

   These are instructions on how to install C++ release 3.0.3.  These
instructions will cover the simple mechanics of installing the
translator on your machine.  Please be sure to read the various
associated README's as well.  These discuss new features and changes
from previous releases and are intended to answer several frequently
asked questions.  Reference to this material should save you time in
getting the answer you need immediately and will allow us to
concentrate on those problems which arise which require assistance.


DOCUMENTATION
-------------
   We will be sending four documents on C++ 3.0.  If you would
like additional copies of the C++ 3.0 product documentation, feel
free to xerox the books or contact us at 908-582-7009 to order
more copies.

Order the documents by the following titles:

C++ Language System Release 3.0.3 Release Notes
C++ Language System Release 3.0.2 Selected Readings
C++ Language System Release 3.0.2 Library Manual         
C++ Language System Release 3.0 Product Reference Manual

The "C++ Standard Components, Release 3" manual set may be ordered
by calling (908) 582-5880, AT&T Software & Documentation Services. 
This is a set of three books containing the manuals and tutorials on
the C++ Standard Components.

Provide them with the following information:

        Document number - B24B
        Title of Book - "C++ Standard Components, Release 3"
        
        Your Name, mailing address and WPN*
                        
* If you DO NOT have a WPN, you will be instructed on what to do.

   If you are a system administrator and are installing C++ for a
developer, please forward the READMEs, the known.problems, the man 
pages, and the paper documentation to your C++ users.

3B2 and VAX USERS
-----------------
   If you are receiving 3b2 executables, we have two types.  One
is for older machines which do not have a mau (floating point
emulator) and one is for machines which do have one.  The directory
name will be either 3b2mau (for machines which have mau's) or 
3b2nomau (for machines which don't).  If you got the wrong version,
please let us know.  If you are receiving vax executables, be aware
that the vax paging executables we distribute will not work on vax
swapping systems.  If you are on a vax swapping system, we will be
happy to send you source so that you can build cfront yourself.


SHIPPING LIST
-------------
   You should have received (or will be receiving shortly) the
following files in /usr/spool/uucppublic/username/C++/3.0/machine_name
where machine_name is one of vax, 3b2mau, 3b2nomau, 6386, 6386-svr4,
sun3, sun4, solaris, uts, sgi, pyr, tandem, hp8.0, or hp on $uucpname:

CC - The shell script for C++.
README3.0 - Notes about the changes between 2.1 C++ and 3.0 C++.
README3.0.1 - Notes about the changes between 3.0 C++ and 3.0.1 C++.
README3.0.2 - Notes about the changes between 3.0.1 C++ and 3.0.2 C++.
README3.0.3 - Notes about the changes between 3.0.2 C++ and 3.0.3 C++.
README.SC - Notes about the Liberty Corner L5 C++ library package.
README.convert - Notes about converting  from L4 to L5 format.
README.preinst - Notes about the preinst tool.
incl.cpio - The C++ include files (cpio format).
incl_mk.cpio - The makefile for the C++ include files (cpio format).
demos.cpio - The C++ and L5 demo programs.
man.cpio - manual pages for C++ , the libraries, and the tools
cfront - The C++ translator.
patch (for most machines) or munch (for HP and Solaris) - The second pass of 
	the C++ translator.
libC.a - The C++ library.
libcomplex.a - The complex arithmetic library
libtask.a - The task library (available for 3B's, sun3, 6386, and vax)
lib++.a - The main part of the Liberty Corner L5 C++ library package
libfs.a - The Liberty Corner L5 C++ free store libraries
libGraph.a - The Liberty Corner L5 C++ Graph libraries
libGA.a - The Liberty Corner L5 C++ Graph Algorithms libraries
libg2++.a - The Liberty Corner L5 C++ G2++ libraries
g2++comp - The G2++ compiler, which converts G2++ specification
	files into C++ programs
c++filt - executable needed to demangle C++ names
incl.sh and incl2 - programs to determine header file dependencies
ptcomp - Template instantiation pre-compiler
ptlink - Template instantiation pre-linker
ncsl and ncsldiff - Non-commentary source line filter
dem - C++ name demangler
demangle - a.out demangler
hier and hier2 - class hierarchy drawing program
fsipp, fscpp - symbolic freestore manager
publik and publik2 - class interface printer
L4-5convert.[ch] - Program to convert your applications that use
	the L4 libraries to use L5.
L4toL5 - File that tells you what has changed between the L4 and L5 
	library releases.
preinst - Tool to preinstantiate C++ templates into a single object file.
INSTALLATION - This file.

And on some architectures:
libC_p.a - The profiling C++ library.
lib++_p.a - The profiling L5 C++ library package
libfs_p.a - The profiling L5 C++ free store libraries
libGraph_p.a - The profiling L5 C++ Graph libraries
libGA_p.a - The profiling L5 C++ Graph Algorithms libraries
libg2++_p.a - The profiling L5 C++ G2++ libraries

Debugging Tools
---------------
Note: For those of you who would like to use cscope++, it is now
available (as cscope) through USTOP (UnixR Software Tools Operations
system).  Access to the USTOP system can be accomplished by entering
at "DESTINATION:" prompt
                      nj/whcc/ustop
The registration is done online.  USTOP hotline: (908) 582-5880.


INSTALLATION INSTRUCTIONS
-------------------------
***** Please note that these files REPLACE any files you may have
gotten with earlier C++ distributions.  Therefore you will need to
clean up any old C++ directories.

0.  Uncompress all of the files that have been sent to you.
    ``uncompress *.Z''.

1.  Put CC, cfront, patch (or munch), c++filt, dem, demangle, hier
    incl.sh, publik, fscpp, ncsl, ncsldiff, g2++comp, ptcomp, 
    and ptlink where they can be found when you try to execute them
    - typically /usr/bin, or if you have it, /usr/lbin or /usr/local/bin.

    Note: incl.sh, hier, fscpp and publik are shell scripts which run the
    C++ tools incl2, hier2, fsipp and publik2.  You may need to edit
    them to set certain variables specific to your environment.

2.  Put libC.a, libcomplex.a, lib++.a, libGraph.a, libGA.a, libg2++.a, 
    libfs.a, libtask.a (if you received it), fsipp, incl2, hier2 and publik2
    where CC can find them (typically /usr/local/lib, /lib or /usr/lib).
    If you are on a Sun and are running SunOS, you will have to ranlib
    the libraries after you move them (ranlib libname).

3.  Now you need to BUILD your include files.  You are going to be making your
    new C++ header files from the existing C header files on your machine.
    To do this, I suggest you temporarily make a directory and build 
    them there.  These are the instructions: 

 3.1. mkdir workingdirectory 
 3.2. cd workingdirectory 
 3.3. cpio -icvBd </usr/spool/uucppublic/username/C++/3.0/machinename/incl.cpio 
   cpio -icvBd </usr/spool/uucppublic/username/C++/3.0/machinename/incl_mk.cpio 
 3.4. edit the top of the make.incl makefile and set the variables (OS,
      STDINCL, SYMBOLICLINK, and CPIO) as appropriate for your machine.
 3.5. make -f make.incl

    This will create a directory called "incl" in your workingdirectory
    which will contain the newly built C++ header files.

4.  Put the include files (all the files under incl) in their own 
    subdirectory where CC can find them, say /usr/local/include/CC.
    Therefore, just recursively copy all of the include files to
    /usr/local/include/CC.
    Note: The incl directory contains sub-directories, therefore cp
    may not work, you probably want to do something like:
4.1 cd workingdirectory/incl
4.2 find . -print | cpio -pdm /usr/include/CC
    
5.  Unbundle (cpio -icvd <man.cpio) the manual page files (man.cpio) 
    and put them in   /usr/man   or   /usr/catman  (or wherever is 
    best on your system).

You will need to edit the CC shell script to set the locations of
all these files.  If you look at lines 13-15, you will see the default
locations.  If you are putting them in a different place, you
will need to change these variables (CCROOTDIR, CCLIBDIR, and I).

For example, if you put the include files in /usr/local/include/CC, 
the libraries in /usr/local/lib,  and the binaries (CC, cfront, patch 
(or munch), and c++filt) in /usr/local/bin, you should set the following 
variables:

CCROOTDIR=${CCROOTDIR-/usr/local/bin}
CCLIBDIR=${CCLIBDIR-/usr/local/lib} 
I=${I-/usr/local/include/CC}

You may want to keep your old version of CC and call this one nCC
(for new CC) or some other name.  To do this, copy CC to its new
name (nCC) in someplace where it can be found in your PATH, and edit
the shell script nCC so that it can find the the correct locations
of the variables discussed above.

If you are on an Amdahl (uts) machine, you need to be using the
native compiler.  You can get this by setting the environment
variable CCS=native.

ALTERNATE FILE INSTALLATION INSTRUCTIONS
----------------------------------------
In release 3.0.2 we have included an 'install' target in the makefile,
delivered in the incl_mk.cpio file.  The 'install' target should be
run after you have built your include files.  NOTE: The install target
assumes that the "incl" directory is in the same directory as the
executables and libraries.  If you followed the directions in step 3
above, and workingdirectory is not the same directory where the
executables and libraries are located, you must either copy the 
incl directory to where the executables are or all of the .a's and
executables to workingdirectory.

Before you use the 'install' target you must edit the makefile and set 
the following variables:

# command used to copy a directory tree of newly built header files
# from the incl-master directory to the top level
CPIO    = cpio -pdm

# these directories are used for installation via "make install"
INSTALL         = cp
INSTALL_BIN     = /usr/bin
INSTALL_LIB     = /usr/lib
INSTALL_INC     = /usr/include/CC

The 'install' target will install the files as described in steps
1,2 and 4 above.  The makefile will also edit the CC, incl.sh, hier,
fscpp and publik shell scripts (as described above) for you.

DEMOS
-----
The file demos.cpio contains canned demo programs for the C++ compiler and
the libraries.  If you would like to confirm that the compiler and libraries
have built correctly you can build the demo programs.  As you did with the
include cpio, you want to unpack this cpio in a working directory.

NOTE: Before you run the demos, make sure the location of the C++ executables
($CCROOTDIR) is on your PATH.  Some of the demos execute commands which
are in this directory.

 - mkdir workingdirectory 
 - cd workingdirectory 
 - cpio -icvBd </usr/spool/uucppublic/username/C++/3.0/machinename/demos.cpio 
 - nohup make CC=Location_of_your_CC -f make.demo demos &

If any of the demos fail, then something either went wrong in 
the building of the library or with the demo itself (though
we have tried to make the demos as generic as possible, problems
do occur on some architectures).  Demo failure is indicated by 
printing a ``FAILED'' message to the terminal, and writing a 
demo.r file to the directory containing the demo.  Executing
 
	$ diff demo.V demo.r

will display the difference between the ``expected output''
(demo.V) and actual output (demo.r) of the demo.  If the
difference is obviously due to a system idiosyncrasy rather
than actual program failure, the ``failure'' can be ignored.

Any apparent error during the execution of a demo, such as a
core dump, that is not accompanied by a ``FAILED'' message,
indicates a successful demo.  The set of demos, if any, that
failed, can be listed by saying:

	$ ls src/*/demos/*.r

C++ LIBRARIES
-------------
   You will also receive the L5 C++ library package.  This release
contains the following libraries: Pool, String, List, Objection, Array_alg,
Block, Map, Time, Strstream, ipc (not available for all machines), Bits, Path
Fsm, Set, Graph, Graph Algorithms, Regex, Symbol and G2++.  For this release, 
the binary files for the libraries are divided between several different 
archives (lib++.a, libGraph.a, libGA.a, and libg2++), but they can be
accessed on a compile line with just "-l++".

The README.SC that comes with the package contains more detailed
information on the libraries.  Please read the README.SC before doing 
anything else to get an overall picture of the current state of the 
library package.

The L5 libraries have the same functionality as the L4 libraries, but they
have been rewritten to take advantage of Templates.  Applications that used the
L4 libraries will NOT work with the C++ release 3.0 and the L5 libraries.
We have provided you with the source for a program, L4-5convert.c, that will
convert your applications that used the L4 libraries to use the L5 format.
The README.convert will tell you how to build this conversion application.
The file L4toL5 explains what has changed between the L4 and L5 library releases.

PROFILED LIBRARIES
------------------
Depending on your target architecture you may have received profiled
versions of the C++ libraries (profiled versions of the task and complex
libraries were not included).  If you wish to use prof(1) you can
access these libraries by setting the -p option to the CC driver script.

If you have any problems or questions, please don't hesitate to call
or send e-mail.

   STC Common Support Hotline
   mozart!c++
   (908) 582-7009
