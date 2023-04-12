if (NOT DEFINED _JOB_ASSIGNMENTS_HAS_CXX_20)
    set(_JOB_ASSIGNMENTS_HAS_CXX_20__DEFINED FALSE)

    message(WARNING "Boolean value \"_JOB_ASSIGNMENTS_HAS_CXX_20\" is not defined by parent scope, treating it as false")
    set(_JOB_ASSIGNMENTS_HAS_CXX_20 FALSE)

else()
    set(_JOB_ASSIGNMENTS_HAS_CXX_20__DEFINED TRUE)
endif()


add_executable(DrWebDictionaryFirstImplAndTester tests/DrWebDictionaryFirstImplAndTester.cc)
add_executable(DictSecondImplementationTester tests/DrWebDictionarySecondImplTester.cc)

target_include_directories(DictSecondImplementationTester PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(DrWebDictionaryFirstImplAndTester PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)


add_executable(DrWebTrimSpaces tests/TrimSpaces.c)

option(JOB_ASSIGNMENTS_BUILD_DR_WEB_WITH_CXX20 "If there is support for std_cxx_20 build DrWeb targets with it" ON)

if (${_JOB_ASSIGNMENTS_HAS_CXX_20} AND ${JOB_ASSIGNMENTS_BUILD_DR_WEB_WITH_CXX20})
    message(STATUS "cxx_std for JobAssignments/DrWeb/DictSecondImplementationTester set to cxx_std_20")
    target_compile_features(DictSecondImplementationTester PRIVATE cxx_std_20)

    message(STATUS "cxx_std for JobAssignments/DrWeb/DrWebDictionaryFirstImplAndTester set to cxx_std_20")
    target_compile_features(DrWebDictionaryFirstImplAndTester PRIVATE cxx_std_20)
endif()


if (NOT _JOB_ASSIGNMENTS_HAS_CXX_20__DEFINED)
    unset(_JOB_ASSIGNMENTS_HAS_CXX_20)
endif ()

unset(_JOB_ASSIGNMENTS_HAS_CXX_20__DEFINED)