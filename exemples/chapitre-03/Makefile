

CC       = gcc
CFLAGS   = -Wall
LOADLIBS = -lcrypt

EXE = crypt


.phony: all

all: $(EXE)

crypt: crypt.c
	$(CC) $(CFLAGS) -o $@ $< $(LOADLIBS)


.phony: clean
clean:
	rm -f $(EXE) *.o


