TEST       = teste

LIBNAME    = celectric

INCLUDEDIR = include/
SRCDIR 	   = ./src/
EXMDIR	   = ./examples/

CC=gcc
CFLAGS=-c -Wall
ARCHIVER=ar rcs

all: lib cleanobj

lib: $(SRCDIR)electric_power.c
	$(CC) -I$(INCLUDEDIR) $(CFLAGS) $(SRCDIR)electric_power.c -o $(LIBNAME).o
	$(ARCHIVER) lib$(LIBNAME).a $(LIBNAME).o

runtest: lib test cleanobj

test: $(TEST).o 
	$(CC) -o $(TEST).run $(TEST).o lib$(LIBNAME).a

$(TEST).o: $(EXMDIR)$(TEST).c
	$(CC) -I$(INCLUDEDIR) $(CFLAGS) $(EXMDIR)$(TEST).c

lib$(LIBNAME).a: $(SRCDIR)electric_power.c
	$(CC) -I$(INCLUDEDIR) $(CFLAGS) $(SRCDIR)electric_power.c -o electric_power.o
	$(ARCHIVER) lib$(LIBNAME).a electric_power.o

cleanobj:
	rm -rf *o

cleana:
	rm -f *a

clean:
	rm -rf *.o *.a $(TEST).run
