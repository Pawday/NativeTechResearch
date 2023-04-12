project(IDETests)

add_library(CPPConstexprTest OBJECT CPPConstexprTest.cc)


option(IDE_TESTS_HIGHEST_CXX_STD_FOR_TARGETS "If target support multiple cxx standards set the highest if possible" OFF)

list(FIND CMAKE_CXX_COMPILE_FEATURES cxx_std_17 _HAS_CXX_17)

if(${_HAS_CXX_17} EQUAL -1)
    set(_HAS_CXX_17 FALSE)
else()
    set(_HAS_CXX_17 TRUE)
endif()

if(${_HAS_CXX_17} AND ${IDE_TESTS_HIGHEST_CXX_STD_FOR_TARGETS})
    message(STATUS "cxx_std for IDETests/CPPConstexprTest set to cxx_std_17")
    target_compile_features(CPPConstexprTest PRIVATE cxx_std_17)
endif()

unset(_HAS_CXX_17)

