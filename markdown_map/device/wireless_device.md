# process of initializing usb wifi adapter

- steps
  - Device Detection: When you plug in your USB WiFi adapter (07b8:b21d), the xhci_hcd (USB 3.0/3.1 host controller driver) detects the device and initializes it.

  - Driver Loading: The rt73usb driver is loaded automatically to manage the USB WiFi adapter. This driver is responsible for providing the necessary communication between the adapter and your Linux operating system.

  - Firmware Loading: The rt73usb driver then proceeds to load the firmware file rt73.bin onto the device. Firmware is a piece of software that runs directly on the hardware of the WiFi adapter, providing essential functionality such as handling radio signals and communicating with networks.

  - Connection Establishment: After loading the firmware, the WiFi adapter (wlx00120e533f54) goes through the process of associating with a WiFi network (authenticate, associate). This process involves exchanging authentication and association messages with the WiFi access point.

- Driver to PC Relationship: The rt73usb driver is provided by the Linux kernel and is responsible for managing the USB WiFi adapter (07b8:b21d). It facilitates communication between the adapter and the operating system.
- Firmware: The firmware (rt73.bin) is specific to the hardware of the WiFi adapter and is loaded onto the adapter by the rt73usb driver. It is not downloaded to your PC's storage; rather, it remains in the volatile memory (RAM) of the WiFi adapter during operation.
