add_executable(UTF8CharLiteral UTF8CharLiteral.cc)



if(MSVC)
    target_compile_definitions(UTF8CharLiteral PRIVATE U8_WITH_MSVC)

    option(COMPILER_TESTS_MSVC_ALLOW_EMOJI "Allow emoji char literal for msvc compiler" OFF)

    if (${COMPILER_TESTS_MSVC_ALLOW_EMOJI})
        message(WARNING "COMPILER_TESTS_MSVC_ALLOW_EMOJI option set to ON, it will FAIL ENTIRE BUILD")
        target_compile_definitions(UTF8CharLiteral PRIVATE ALLOW_EMOJI=1)
    endif()
endif()