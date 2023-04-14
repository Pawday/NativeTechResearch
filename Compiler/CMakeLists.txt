cmake_minimum_required(VERSION 3.10)

project(CompilerTests)

include(UTF8CharLiteralSegregatedFile.cmake)

if (MSVC)
    add_library(DeadCodeOptimisationTests OBJECT DeadCodeTest.c)
else()
    add_executable(DeadCodeOptimisationTests DeadCodeTest.c)
endif()


add_executable(FunctionCallTest FunctionCall.c)