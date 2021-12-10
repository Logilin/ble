ifneq (${KERNELRELEASE},)

		obj-m  = exemple-01.o
		obj-m += exemple-02.o
else

	MODULE_DIR := $(shell pwd)

	# Repertoire contenant les sources du noyau cible.
	KERNEL_DIR ?= /lib/modules/$(shell uname -r)/build

	CFLAGS := -Wall -g

all: modules

modules:
	${MAKE} -C ${KERNEL_DIR} M=${MODULE_DIR}  modules

clean:
	rm -f *.o *.ko *.mod.c .*.o .*.ko .*.mod.c .*.cmd *~ *.ko.unsigned *.mod
	rm -f Module.symvers Module.markers modules.order
	rm -rf .tmp_versions .cache.mk

endif

