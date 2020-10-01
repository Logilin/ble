CFLAGS+=-Wall -g

ifeq ($(CC),cc)

	CROSS_COMPILE ?=
	CC = $(CROSS_COMPILE)gcc
endif

.PHONY: all
all: hello

hello: hello.c
	${CC} ${CFLAGS} hello.c -o hello

.PHONY: clean
clean:
	rm -f hello
