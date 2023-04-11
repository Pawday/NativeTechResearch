# Compiler tests

### This directory contains examples for testing C or C++ compiler
## Summary:

- [UTF8CharLiteral.cc](./UTF8CharLiteral.cc)
  contains example code for testing UTF8 support on C++ compilers
  - [CPPReference](https://en.cppreference.com/w/cpp/language/character_literal) on that
  - [C++ std Lex Draft](https://eel.is/c++draft/lex.ccon#1)
  - LLVM [issue](https://github.com/llvm/llvm-project/issues/15471) about UTF8 literals
- [DeadCodeTest.c](./DeadCodeTest.c) contains example with conditional call of function depending on constexpr
  - MSVC Keeps symbols on Debug Builds
  - LLVM (and GCC) eliminate dead symbols even in debug mode (I've tried to disable that thing, but it seems there is no option for that. In LLVM/Clang dead symbols elimination happening before codegen and i have no any idea how to deal with it)
  - My [FFMPEG cmake port](https://github.com/Pawday/ffmpeg-cmake) project stops on this issue. 
  - My related [patch](http://ffmpeg.org/pipermail/ffmpeg-devel/2023-January/305899.html) to ffmpeg
  - My related [question](https://stackoverflow.com/questions/71728589/why-do-ffmpeg-developers-use-runtime-if-with-macrofied-condition) on StackOverflow