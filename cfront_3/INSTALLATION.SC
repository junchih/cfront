Subject: Standard Component release L5 source installation letter

Dear Standard Component - L5 Customer-

   These are instructions on how to install C++ release L5.  These
instructions will cover the mechanics of building and installing the
libraries on your machine.  Please read the following instructions
carefully.  In addition, if you would prefer to save the effort
required to build the libraries yourself, we do distribute binary
versions for 3B2 (both mau and no mau), 6386 (SVR3 and SVR4), hp9000
(HP-UX 7.0 and 8.0), pyramid, tandem, vax (paging), uts (amdahl),
sun3, and sun4.

DOCUMENTATION
-------------
The "C++ Standard Components, Release 3" manual set may be ordered
by calling (908) 582-5880, AT&T Software & Documentation Services.
This is a set of three books containing the manuals and tutorials on
the C++ Standard Components.

Provide them with the following information:

        Document number - B24B
        Title of Book - "C++ Standard Components, Release 3"

        Your Name, mailing address and WPN*

* If you DO NOT have a WPN, you will be instructed on what to do.

SHIPPING LIST
-------------
   You should have received (or will be receiving shortly) the
following cpio files in /usr/spool/uucppublic/username/C++/L5/source
on your machine:

1: top.cpio, the top-level files which contains:
    README - Notes/hints about the Liberty Corner L5 C++ libraries.
    INSTALLATION - This file.
    makefile - The make file for making the libraries.
    aux - build rule directory for L5 libraries.
    L4-5convert.[ch] - Source code for a L4 to L5 conversion tool (make
	sure you read the README.convert before you use this tool).
    README.convert - Notes about the conversion tool.
2: man.cpio - the man pages.
3: inclSC.cpio - The L5 include files .
4: libSC0.cpio - The source files needed to create lib++.a, libfs.a,
		 libGA.a, libGraph.a, libg2++.a and L5 tools.
5: libSC1.cpio - More source files for libraries and tools.

If you didn't receive all of these, please let me know and I'll re-uucp
them.  All the files are in cpio format.  You will need to uncpio all of
them.  To do this, you can use the command:

UNPACKING THE CPIO's
--------------------
cd workingdirectory (Whatever directory you want to put the stuff in)
cpio -icvd < /usr/spool/uucppublic/username/C++/L5/source/top.cpio
cpio -icvd < /usr/spool/uucppublic/username/C++/L5/source/man.cpio
cpio -icvd < /usr/spool/uucppublic/username/C++/L5/source/libSC0.cpio
cpio -icvd < /usr/spool/uucppublic/username/C++/L5/source/libSC1.cpio
cpio -icvd < /usr/spool/uucppublic/username/C++/L5/source/inclSC.cpio

When you finish unpacking the cpio's your working directory will
have the following subdirectories:

1. aux - contains the build scripts.
2. SCincl - the include files for the libraries.  These must be
    moved to where your C++ header files reside.
3. libSC - this contains the source (and demos) for the libraries.
4. man - manual pages.

BUILD PROCEDURES FOR RELEASE L5
--------------------------------
Here is a summary of the steps to build release L5.  Note:
To build these libraries you need the equivalent of USL's 3.0.1
(or greater) C++ translator.  These libraries have been implemented
using template features that were not available before the 3.0.1
release.
	1. Install the include files you received with this distribution
	   (workingdirectory/SCincl/*) where your C++ compiler looks for
	   header files.

	2. Edit the top-level makefile, changing variables at the top
	   as needed.  Be sure to set CC = to the name of your C++
	   driver script.

	2a. Edit the libSC/aoutdem/makefile and set OS for your machine.
	   This is needed to build an a.out demangler for your system.

	3. Run either:	make sc3.0
			make sc3.0_p - profiled version of the libraries (this
				assumes your CC knows what to do with -p)
			make clean
			make demos

	   Note on demos:

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

NOTES
-----

1. If the ipc component fails to compile because 'struct semun' is undefined,
   then add '-D__ATT_SEMUN' to CCFLAGS in the top-level makefile.

2. The Strstream component was recently changed to improve the efficiency
   of the iStrstream class.  This change is link-incompatible with previous
   versions of L5.  If maintaining link-compatibility is important,
   then add '-DL5_COMPATIBLE' to CCFLAGS in the top-level makefile.

3. If L5 is being compiled with the AT&T C++ 4.0 compiler, then two other
   versions of the libraries may be built:
	make sc3.0_b - 3.0 link-compatibility libraries (4.0 CC option -b)
	make sc3.0_eh - EH versions of the libraries (4.0 CC option -x)

INSTALLATION OF LIBRARIES
-------------------------
**** Please note that these files replace any files you may have
received with earlier C++ distributions; therefore you should clean up
all your C++ directories before you start installing the new files.

1.  Put dem, demangle, hier, incl.sh, publik, fscpp and g2++comp where they can
    be found when you try and execute them - typically /usr/bin, or if you
    have it, /usr/lbin or /usr/local/bin.

    Note: incl.sh, hier and publik are shell scripts which run the
    C++ tools incl2, hier2 and publik2.  You may need to edit
    them to set certain variables specific to your environment.

2.  Put lib++.a, libGraph.a, libGA.a, libg2++.a, libfs.a, fsipp, incl2, hier2
    and publik2 in either /lib or /usr/lib.  If you are on a sun, you will
    have to ranlib the libraries after you move them (ranlib libname).

3.  Put the man files in   /usr/man   or   /usr/catman
    (or wherever is best on your system).

4.  The source code files and the makefile can be put anywhere on your
    system (or delete them if you want).

C++ LIBRARIES
-------------
This release contains the following libraries: Pool, String, List, Objection,
Array_alg, Block, Map, Time, Strstream, ipc (not available for all machines),
Bits, Path Fsm, Set, Graph, Graph Algorithms, Regex, Symbol and G2++.  For
this release, the binary files for the libraries are divided between several
different archives (lib++.a, libGraph.a, libGA.a, and libg2++).

The README that comes with the package contains more detailed
information on the libraries.  Please read the README before doing
anything else to get an overall picture of the current state of the
library package.

The L5 libraries have the same functionality as the L4 libraries, but they
have been rewritten to take advantage of Templates.  Applications that used the
L4 libraries will NOT work with the C++ release 3.0 and the L5 libraries.

If you have any problems or questions, please don't hesitate to call
or send e-mail.

   Valerie Monroe Kloss
   mozart!vjm
   (908) 582-7009
