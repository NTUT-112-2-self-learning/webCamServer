# Embedded linux

## bootloader

0. SoC powered
    - SoC powered and give control to ROM Bootloader
1. SoC ROM Bootloader
    - boot the first stage bootloader
2. first Stage Bootloader
    - SPL/MLO (secondary program loader/memory loader)
    - decide whether the next stage bootloader is on the rom in raw mode(binary) or boot file
3. second Stage Bootloader
    
## Kernel
