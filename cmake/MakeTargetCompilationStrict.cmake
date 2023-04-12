function(MakeTargetCompilationStrict TARGET)

    if (NOT MSVC)
        target_compile_options(${TARGET} PRIVATE "-Wall" "-Wextra" "-pedantic")
    endif()

endfunction()