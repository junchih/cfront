.  \"ident	"@(#)cls4:man/stream/cover.mm	1.1"
.  \"Copyright (c) 1984 AT&T
.  \"All Rights Reserved        
.  \"THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T
.  \"The copyright notice above does not evidence any           
.  \"actual or intended publication of such source code.
.TL "3115-31-0101" "49059-6"
Iostreams
.AU "Jerry Schwarz" jss MH 59554 5406 3C-536B "uucp: ulysses!jss" 
.AS
I/O in C++ can use either the C \fIstdio\fR package or the
\fIstream\fR package.  I recently rewrote the \fIstream\fR package.
This document contains the man pages for the revised I/O package,
called \fIiostreams\fR.  This package is being considered for
inclusion in release 2.0 of the AT&T C++ Translator.
.AE
.MT 4
.H 1 "Highlights"
.BL
.LI
There is a single \fBiostream\fR class supporting both input and output.
See \fIIOS.INTRO\fR(3) and \fIiostream\fR(3).
.LI
The \fBstreambuf\fR class has been redesigned.  "Buffers" are 
an independent abstraction not solely a part of the
I/O package.  See \fIsbuf.pub\fR(3) and \fIsbuf.prot\fR(3). 
.LI
More flexible formatting is supported.  See \fIios.in\fR(3) and
\fIios.out\fR(3).
.LI
Manipulators are supported.  See \fImanip\fR(3).
.LI
Various specialized derived streambuf classes are included.  
See \fIfilebuf\fR(3), \fIpipebuf\fR(3), \fIssbuf\fR(3) and \fIstdiobuf\fR(3) 
.LI
A specialized class derived from iostream for use with files is
included.  See \fIfstream\fR(3).
.LI
A specialized class for "incore" operations is included.
See \fIstrstream\fR(3).
.LI
Bugs have been fixed.
.LE
.H 1 Contents
.TS
tab(:);
c c
l l.
man page	contents
_
IOS.INTRO:general description of iostream package
filebuf:streambuf specialized to files
fstream:iostream specialized to files
ios.in:iostream input operations
ios.out:iostream output operations
iostream:description of iostream class
manip:manipulators
pipebuf:streambuf specialized to a circular queue
pipestream:iostream specialized for circular queue
sbuf.prot:streambuf protected interface (for derived classes)
sbuf.pub:streambuf (buffer abstraction) public interface
ssbuf:streambuf specialized for incore formatting
stdiobuf:streambuf and iostream specialized for stdio FILEs
strstream:iostream specialized for incore formatting
.TE
