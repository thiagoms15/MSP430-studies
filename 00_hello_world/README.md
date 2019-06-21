## This repository is a hello world with MSP430 on Arch Linux

___
# 1 - How to set up the environment

Install the follow packets:

* gcc-msp430-opensource
* mspdebug

## 1.1 - gcc-msp430-opensource
The _latest_ version of *gcc-msp430-opensource* you can get it, acessing the [TI](http://www.ti.com/tool/msp430-gcc-opensource).
I am using the *[msp430-gcc-full-linux-x64-installer-6.1.1.0](https://www.ti.com/licreg/docs/swlicexportcontrol.tsp?form_type=2&prod_no=msp430-gcc-full-linux-x64-installer-6.1.1.0.run&ref_url=http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSPGCC/latest/)* version.

After downloaded the SDK from Texas Instruments, you need to change the permission for execute it.

```
# change the permission to execute
$ chmod a+x msp430-gcc-full-linux-x64-installer-6.1.1.0.run 

# execute the installer
$ sudo ./msp430-gcc-full-linux-x64-installer-6.1.1.0.run
```
*Note: When you are installing the files, choose the path:*  **/opt/ti/msp430-gcc** .

## 1.2 - mspdebug

```
$ yaourt -S mspdebug
```
___

# 2 - How to build the project

This project uses a Makefile to build the _elf file_ .
```
$ make
```
___

# 3 - Flash the target
After the binary was generated, connect the MSP430 to computer and execute the follow commands to flash and run.

```
$ mspdebug rf2500

(mspdebug) prog msp430g2553.out

(mspdebug) run

```
___

# 4 - Using the gdb

In the first terminal start the *GDB-server*.

```
$ mspdebug rf2500 gdb
```

In the second terminal connect to the server at the port opened.

```
$ /opt/ti/msp430-gcc/bin/msp430-elf-gdb msp430g2553.out

(gdb) target remote localhost:2000
```
___
[comment]: <> (/opt/ti/msp430-gcc/bin/msp430-elf-gdb msp430g2553.out ;set remoteaddresssize 64 ;set remotetimeout 999999 ;target remote localhost:2000)