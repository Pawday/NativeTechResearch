cmake_minimum_required(VERSION 3.10)

project(CXX_TemplatesTests)

add_executable(AckermannTemplated AckermannTemplated.cc)
add_executable(CharAndCompileTime CharAndCompileTime.cc)
add_executable(TemplateFactorial TemplateFactorial.cc)

add_executable(TypeList MetaList.cc)
target_compile_features(TypeList PRIVATE cxx_std_20)

add_executable(SFINAEBeginning SFINAEBeginning.cc)