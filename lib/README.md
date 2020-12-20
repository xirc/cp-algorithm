# Competitive Programming Library & Examples

This project contains Competitive Programming Library and its' examples.

## Project Structures

### [cpalgo](./cpalgo)

C++ header library.  
The headers should be easily copyable during a programming contest.

### [main](./main)

Executable binaries to show usage of the library.

## How to build

To build all executable binaries run the following command.

```shell
bazelisk build //main/...:*
```

## How to test library code

To test library code run the following command.

```shell
bazelisk test //cpalgo/...:*
```