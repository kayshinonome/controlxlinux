# controlxlinux

[![C/C++ CI](https://github.com/tsuki-superior/controlxlinux/actions/workflows/build.yml/badge.svg)](https://github.com/tsuki-superior/controlxlinux/actions/workflows/build.yml)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/89f07741b5544bf6b35e696c49c7baea)](https://www.codacy.com/gh/tsuki-superior/controlxlinux/dashboard?utm_source=github.com&utm_medium=referral&utm_content=tsuki-superior/controlxlinux&utm_campaign=Badge_Grade)

A tool to help you make controlx compatible images for the TI-nspire

While I am not responsible for any damage caused to your calculator due to this tool, I can inform you that this tool was indeed tested on real hardware, and worked perfectly.

## Usage

```sh
controlxlinux <dtb> <initrd> <kernel> <output_file>

```

## Building

```sh
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
sudo make install
```

## Debian package

You can make a debian package too

```sh
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make package
```
