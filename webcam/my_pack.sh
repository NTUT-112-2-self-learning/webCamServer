#!/bin/sh
chip=ssc325
variant=lite
flavor=with_mt76

uboot=u-boot-$chip-nor.bin
uImage=uImage.$chip
rootfs=rootfs.squashfs.$chip

release=openipc-$chip-nor-$variant.bin

dd if=/dev/zero bs=1K count=8192 status=none | tr '\000' '\377' > $release
dd if=u-boot_downloaded/$uboot of=$release bs=1K seek=0 conv=notrunc status=none
dd if=$flavor/$uImage of=$release bs=1K seek=320 conv=notrunc status=none
dd if=$flavor/$rootfs of=$release bs=1K seek=2368 conv=notrunc status=none

echo "Created: $release"


CONFIG_MT7601U=m


# BR2_PACKAGE_MT7601U_OPENIPC=y
# v.s.
# BR2_PACKAGE_LINUX_FIRMWARE_OPENIPC=y
# BR2_PACKAGE_LINUX_FIRMWARE_OPENIPC_MEDIATEK_MT7601U=y