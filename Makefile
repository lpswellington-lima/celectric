TEST       = teste

LIBNAME    = celectric

INCLUDEDIR = include/
SRCDIR 	   = ./src/
EXMDIR	   = ./examples/

CC=gcc
CFLAGS=-c -Wall
ARCHIVER=ar rcs

all: lib cleanobj

lib: $(SRCDIR)electric_power.c $(SRCDIR)grounding.c
	$(CC) -I$(INCLUDEDIR) $(CFLAGS) $(SRCDIR)electric_power.c -o electric_power.o -lm
	$(CC) -I$(INCLUDEDIR) $(CFLAGS) $(SRCDIR)grounding.c -o grounding.o -lm
	$(ARCHIVER) lib$(LIBNAME).a electric_power.o grounding.o

runtest: clean lib test cleanobj

test: $(TEST).o 
	$(CC) -o $(TEST).run $(TEST).o lib$(LIBNAME).a -lm

$(TEST).o: $(EXMDIR)$(TEST).c
	$(CC) -I$(INCLUDEDIR) $(CFLAGS) $(EXMDIR)$(TEST).c

cleanobj:
	rm -rf *o

cleana:
	rm -f *a

clean:
	rm -rf *.o *.a $(TEST).run
