# MLO vs IPL

## IPL (Initial Program Loader)

- Function: The IPL is the first piece of code executed by the processor after a reset. Its primary role is to initialize the minimal hardware required to load the next stage of the boot process.
- Responsibilities:
  - Basic hardware initialization.
  - Setting up memory (RAM) if required.
  - Loading and executing the next stage bootloader from a non-volatile storage (like NOR/NAND flash or eMMC).
- Example: In some systems, IPL might set up the system to a point where it can load U-Boot or another secondary bootloader.

## MLO (Main Loader)

- Function: MLO is a term commonly used in the context of Texas Instruments' OMAP and Sitara processors. It refers to the second stage bootloader that is responsible for more extensive hardware initialization and loading the final bootloader (like U-Boot).
- Responsibilities:
  - More comprehensive hardware initialization compared to IPL.
  - Setting up clocks, peripherals, and memory.
  - Loading the final bootloader into RAM and executing it.
- Example: In TI's boot process, the MLO file is the first code loaded by the ROM bootloader. It sets up the system enough to load and run U-Boot.
