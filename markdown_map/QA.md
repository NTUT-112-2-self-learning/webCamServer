# Q&A in the process

- why SSC325 image for SSC323 chipset hardware?
    both from infinity6 series
- Any difference between u-boots for SSC325 & SSC323?
- kernel panic (unable to mount the rootfs)
- no wifi interface in system
- where to install the driver for MT7601U
- what does the script "general/overlay/etc/wireless/usb" do
  - load (or "modprobe") the appropriate Linux kernel module for a given USB wireless adapter.
  - defines a function set_gpio that sets or clears a GPIO pin $1 based on $2
  - checks the $1 and loads the corresponding kernel module using the modprobe command.
  - After loading the appropriate module, the script exits with a status of 0, indicating success.
  - probably called with the appropriate argument when a USB wireless adapter is plugged in.
