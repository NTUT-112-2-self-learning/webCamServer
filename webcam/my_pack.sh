#!/bin/sh
#ssc333 or ssc325
chip=ssc325
# flavor=origin_firmware_generated
# flavor=with_mt76
flavor=without_majestic

uboot=u-boot-$chip-nor.bin
uImage=uImage.$chip
rootfs=rootfs.squashfs.$chip


release=image/$chip-$flavor.bin
if [ -f "$release" ]; then
    echo "removing $release..."
    rm $release
    echo "removed. Generating $release ..."
else
    echo "$release does not exist. Generating..."
fi


if [ -f "u-boot_downloaded/$uboot" ]; then
    echo "U-Boot image exists."
else
    echo "U-Boot image is missing."
    exit 1
fi

if [ -f "$flavor/$uImage" ]; then
    echo "uImage exists."
else
    echo "uImage is missing."
    exit 1
fi

if [ -f "$flavor/$rootfs" ]; then
    echo "Rootfs image exists."
else
    echo "Rootfs image is missing."
    exit 1
fi

dd if=/dev/zero bs=1K count=8192 status=none | tr '\000' '\377' > $release
dd if=u-boot_downloaded/$uboot of=$release bs=1K seek=0 conv=notrunc status=none
dd if=br/$flavor/$uImage of=$release bs=1K seek=320 conv=notrunc status=none
dd if=br/$flavor/$rootfs of=$release bs=1K seek=2368 conv=notrunc status=none

echo "Created: $release"


# CONFIG_MT7601U=m


# BR2_PACKAGE_MT7601U_OPENIPC=y
# v.s.
# BR2_PACKAGE_LINUX_FIRMWARE_OPENIPC=y
# BR2_PACKAGE_LINUX_FIRMWARE_OPENIPC_MEDIATEK_MT7601U=y