SUBDIRS	= $(wildcard *)

all:
	@set -e;                                 \
	for i in $(SUBDIRS);                     \
	do                                       \
		if [ -d $$i ]; then              \
			cd $$i;                  \
			if [ -f Makefile ]; then \
				make;            \
			fi;                      \
			cd -;                    \
		fi;                              \
	done

clean: 
	@set -e;                                 \
	for i in $(SUBDIRS);                     \
	do                                       \
		if [ -d $$i ]; then              \
			cd $$i;                  \
			if [ -f Makefile ]; then \
				make clean;      \
			fi;                      \
			cd -;                    \
		fi;                              \
	done

