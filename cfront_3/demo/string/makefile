CC=CC
LIBS=
CCFLAGS=-DNO_EXCEPTION
ISTL=--stl -I../../stl
G=
LDFLAGS=$(G)
SHELL=sh

.SUFFIXES: .E
 
.c.E:
	$(CC) $(CCFLAGS) $(ISTL) $(LDFLAGS) -o $*.E $< $(LIBS)

.c.o:
	$(CC) $(CCFLAGS) $(ISTL) -c $<

all:
	$(SHELL) ./regress

clean:
	rm -f *.o *.E *.r *.ii core
	rm -rf ptrepository
