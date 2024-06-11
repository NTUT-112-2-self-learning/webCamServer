# OPENIPC firmware build process

## dir

``` bash
drwxr-xr-x 19 james james  4096 May 26 13:10 .
drwxr-xr-x  3 james james  4096 May 26 00:04 ..
drwxr-xr-x  4 james james  4096 May 26 00:04 br-ext-chip-allwinner
drwxr-xr-x  4 james james  4096 May 26 00:04 br-ext-chip-ambarella
drwxr-xr-x  4 james james  4096 May 26 00:04 br-ext-chip-anyka
drwxr-xr-x  4 james james  4096 May 26 00:04 br-ext-chip-fullhan
drwxr-xr-x  4 james james  4096 May 26 00:04 br-ext-chip-goke
drwxr-xr-x  4 james james  4096 May 26 00:04 br-ext-chip-grainmedia
drwxr-xr-x  4 james james  4096 May 26 00:04 br-ext-chip-hisilicon
drwxr-xr-x  4 james james  4096 May 26 00:04 br-ext-chip-ingenic
drwxr-xr-x  4 james james  4096 May 26 00:04 br-ext-chip-novatek
drwxr-xr-x  4 james james  4096 May 26 00:04 br-ext-chip-rockchip
drwxr-xr-x  4 james james  4096 May 26 00:04 br-ext-chip-sigmastar
drwxr-xr-x  4 james james  4096 May 26 00:04 br-ext-chip-ti
drwxr-xr-x  4 james james  4096 May 26 00:04 br-ext-chip-xiongmai
-rw-r--r--  1 james james 66473 May 26 00:04 .editorconfig
drwxr-xr-x  5 james james  4096 May 26 00:04 general
drwxr-xr-x  8 james james  4096 May 26 15:58 .git
drwxr-xr-x  3 james james  4096 May 26 00:04 .github
-rw-r--r--  1 james james    33 May 26 00:04 .gitignore
-rw-r--r--  1 james james  1064 May 26 00:04 LICENSE
-rw-r--r--  1 james james  4193 May 26 15:44 Makefile
drwxr-xr-x  6 james james  4096 May 26 15:58 output
-rw-r--r--  1 james james  2733 May 26 00:04 README.md
```

## Cmake

running make without specifying a target, make will run the first target in the Makefile which is `make all`, consist the following actions:

```c
all
{
    build
    {
        defconfig (preparing the build configuration)
        {
            prepare{
                see if buildroot-${BR_VER} exist, if not, do wget for tar file.
            }
            // runs defconfig again in build root with config file path ${BR2_DEFCONwill FIG}
        }
        // runs make all again in the build root
    }
    repack
    {
        packs firmware
    }
    timer
    {
        shows execution time
    }
}
```    

BR2_DEFCONFIG is ./br-ext-chip-sigmastar/configs/msc313e_lite_defconfig in this case

`./Makefile` BR2_EXTERNAL=$(PWD)/general    
`./Makefile` BR2_DEFCONFIG=$(PWD)/$(CONFIG) defconfig

`./general/external.mk` OPENIPC_TOOLCHAIN -> latest/$(shell $(BR2_EXTERNAL)/scripts/show_toolchains.sh $(BR2_DEFCONFIG))

`./general/scripts/show_toolchains.sh` 

`./br-ext-chip-sigmastar/configs/msc313e_lite_defconfig` BR2_TOOLCHAIN_EXTERNAL_URL="<https://github.com/openipc/firmware/releases/download/$(OPENIPC_TOOLCHAIN).tgz>"
