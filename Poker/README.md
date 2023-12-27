# MPoker

Poker Simulator

## Installation

All executable files are found inside the build/bin folder once 
```bash 
$ make
```
has been called. To run an executable file:

```bash
$ mkdir build

$ cd build

$ cmake ..

$ make

$ ./MPoker
```
## DEBUG Mode

Some error messages are hidden unless the DEBUG macro is active:

To activate:
```bash
$ cd build

$ cmake -DDEBUG=ON ..

$ make

$ bin/client 

$ bin/server
```

## Tests

Tests are written with Google's GTest

To run:
```bash
$ cmake -DTest=ON ..

$ make

$ ./tests/tests
```
