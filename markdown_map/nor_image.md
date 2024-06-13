# bootable flash

- case: [image](openipc-ssc325-lite-8mb.bin)

- u-boot
  - IPL
    - offset: 0x000000
    - size: 13567B
    - tries 512MB/256MB/128MB/64MB/32MB/fail for DRAM
  - MXP
    - offset: 0x00F000
    - size: 1000B
  - IPLC
    - offset: 0x010000
    - size: 4680B

- Kernel
  - offset: 0x00050000
  - size: 0x1DA23F

- rootfs
  - offset: 0x00250000
  - size: 0x3E5FFF
