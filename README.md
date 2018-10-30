# TOM

TOM is a COM-inspired component object model for C++.

## Building and installing

```bash
$ git clone https://github.com/handicraftsman/tom
$ cd tom
$ mkdir build
$ cd build
$ cmake .. -DCMAKE_BUILD_TYPE=Release
$ make 
$ sudo make install
```

## Using

This package is available as a Pkg-Config module as `tom`.

It can be used in any build system which supports Pkg-Config under that name.

Usage example can be found in `demo/` and `greeter/` folders.

## ToDo

* Documentation
