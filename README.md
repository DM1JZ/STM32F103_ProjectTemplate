# STM32F103_ProjectTemplate

Template for new projects for STM32F103 uC and libopencm3

This is just a small helper repo to quickly create new test projects. I recommend that you don't use it for your software, as this is a dirty prototype and might have bugs, errors and unexpected behavior. If you are still not afraid, use it and do something cute with it.  
\o/

## Build instructions
dependency for libopencm3 build: python

git submodule init
git submodule update
cd libopencm3
make

cd ../src/
make

## Flash instructions
Configure programmer hardware in libopencm3.target.mk

For BlackMagicProbe:
BMP_Port ?= /dev/ttyACM0 (BMP GDB server port)

Compile with:
 make

Program with:
 make flash

