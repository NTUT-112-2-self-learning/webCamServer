# Infrastructure for packages building kernel modules

- Buildroot offers a helper infrastructure to make it easy to write packages that build and install Linux kernel modules.
- packages
  - kernel module
  - programs
  - libraries

- invoke
  - kernel-module
    - generates all the appropriate Makefile rules and variables to build that kernel module
  - generic-package
    - for build system is not one of the standard ones, such as autotools or CMake build system, based on hand-written Makefiles or shell scripts.
