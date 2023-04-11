add_executable(UTF8CharLiteral UTF8CharLiteral.cc)

if(MSVC)
    target_compile_definitions(UTF8CharLiteral PRIVATE U8_WITH_MSVC)
endif()