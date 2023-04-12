project(CodeWars)

include(MakeTargetCompilationStrict)

add_executable(String_Ends StringEnds.c)
add_executable(Bits_count BitsCount.c)
add_executable(Membership Membership.c)
add_executable(StringSort StringSort.c)
add_executable(EvenIndex FindEvenIndex.c)

MakeTargetCompilationStrict(String_Ends)
MakeTargetCompilationStrict(Bits_count)
MakeTargetCompilationStrict(Membership)
MakeTargetCompilationStrict(StringSort)
MakeTargetCompilationStrict(EvenIndex)

if(MSVC)
    target_compile_definitions(Membership PRIVATE _TESTS_CODEWARS_MSVC)
    target_compile_definitions(StringSort PRIVATE _TESTS_CODEWARS_MSVC)
endif()