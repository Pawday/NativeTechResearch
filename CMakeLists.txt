cmake_minimum_required(VERSION 3.10)

project(C_CXX_Tests)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(CMakeBuildSystemHacks)

DisableIncludeTreeDumpOnNinjaWithMSVC()

add_subdirectory(CxxTemplates)
add_subdirectory(IDETests)
add_subdirectory(Compiler)
add_subdirectory(JobAssignments)
add_subdirectory(CodeWars)
add_subdirectory(Basics)