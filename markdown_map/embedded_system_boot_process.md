# embedded system boot process

## **Initial Program Load (IPL):**

- The boot process starts with the IPL, which initializes the system and verifies checksums.
- The IPL loads from NOR flash memory and finds the Memory Expansion ([MXP](MXP.md)) block at offset `0x0000f000`.

## **U-Boot Initialization:**

- The system enters the U-Boot bootloader, version `2015.01`.
- U-Boot initializes various subsystems including I2C, DRAM (though caches are not enabled), and SPI NOR flash.
- The flash memory (NOR) is detected with a total size of 16 MiB.
- The network interface is initialized but fails to auto-negotiate.

## **Kernel Booting:**

- The system proceeds to boot the Linux kernel, version `4.9.84`.
- The kernel is loaded from a legacy image with a data size of approximately 1.9 MiB.
 The kernel command line specifies parameters such as console settings, panic behavior, root filesystem location, and memory layout.

## **Kernel Initialization:**

- The kernel initializes memory, with a physical offset of `0x20000000` and reserved memory regions.
- The device tree (`fdt`) is processed successfully.
- The system mounts various filesystems, initializes hardware components (e.g., USB, UART, Ethernet), and sets up GPIO and I2C interfaces.

## **Filesystem and Device Management:**

- The root filesystem is mounted as read-only initially.
- Device management subsystems such as `devtmpfs` and `mdev` are started.
- Network configuration starts with `udhcpc` attempting to obtain an IP address via DHCP but failing.

## **User Space Initialization:**

- System services including `syslogd`, `klogd`, `rngd`, `ntpd`, `dropbear` (SSH server), and `crond` (cron daemon) are started.
- Vendor-specific modules and drivers (e.g., for sensors like `gc2053`) are loaded.
- The system presents a login prompt for user interaction.
