cmake_minimum_required(VERSION 3.10)

project(CompilerTests)

include(UTF8CharLiteralSegregatedFile.cmake)

add_executable(DeadCodeOptimisationTests DeadCodeTest.c)