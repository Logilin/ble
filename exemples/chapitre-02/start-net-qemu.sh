#!/bin/sh
IMAGE_DIR="${0%/*}/"

if [ "${1}" = "serial-only" ]; then
    EXTRA_ARGS='-nographic'
else
    EXTRA_ARGS='-serial stdio'
fi

echo '#! /bin/sh'                              > "${IMAGE_DIR}/qemu-ifup"
echo 'ip addr add 192.168.1.10/24 dev $1'     >> "${IMAGE_DIR}/qemu-ifup"
echo 'ip link set dev $1 up'                  >> "${IMAGE_DIR}/qemu-ifup"
chmod +x "${IMAGE_DIR}/qemu-ifup"

export PATH="${IMAGE_DIR}/../host/bin:${PATH}"
exec   qemu-system-arm -M vexpress-a9 -smp 1 -m 256 -kernel ${IMAGE_DIR}/zImage -dtb ${IMAGE_DIR}/vexpress-v2p-ca9.dtb -drive file=${IMAGE_DIR}/rootfs.ext2,if=sd,format=raw -append "console=ttyAMA0,115200 rootwait root=/dev/mmcblk0"  -net nic,model=lan9118 -net tap,script="${IMAGE_DIR}qemu-ifup"  ${EXTRA_ARGS}

rm -f "${IMAGE_DIR}/qemu-ifup"
