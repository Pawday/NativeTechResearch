function(MakeTargetCompilationStrict TARGET)

    if (NOT MSVC)
        target_compile_options(${TARGET} PRIVATE "-Wall" "-Wextra" "-pedantic")
        target_compile_options(${TARGET} PRIVATE "-Wno-gnu-binary-literal")
    endif()

endfunction()