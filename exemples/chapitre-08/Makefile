ifneq (${KERNELRELEASE},)

ifneq (${SOLUTIONS},)
		obj-m  = solution-01.o
		obj-m += solution-02.o
else
		obj-m  = exemple-01.o
		obj-m += exemple-02.o
endif

else

	RPI := 1

	MODULE_DIR := $(shell pwd)

	# Repertoire contenant les sources du noyau cible.
	KERNEL_DIR ?= /lib/modules/$(shell uname -r)/build
	CROSS_KERNEL_DIR ?= 

	# Architecture cible (si differente de celle de l'hote).
	CROSS_ARCH       ?= arm

	# Prefixe du cross-compiler.
	CROSS_COMPILE    ?= 

	CFLAGS := -Wall -g

all: modules

modules:
	${MAKE} -C ${KERNEL_DIR} SUBDIRS=${MODULE_DIR}  modules

cross:
	${MAKE} -C ${CROSS_KERNEL_DIR} SUBDIRS=${MODULE_DIR} ARCH=${CROSS_ARCH} CROSS_COMPILE=${CROSS_COMPILE} modules

solutions:
	${MAKE} -C ${KERNEL_DIR} SUBDIRS=${MODULE_DIR}  modules  SOLUTIONS=1

clean:
	rm -f *.o *.ko *.mod.c .*.o .*.ko .*.mod.c .*.cmd *~ *.ko.unsigned
	rm -f Module.symvers Module.markers modules.order
	rm -rf .tmp_versions

endif

