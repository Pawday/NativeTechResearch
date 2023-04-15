project(CPPBasics)

add_executable(STL_MapTest STL/MapTest.cc)
add_executable(ObjectLifetimeTests ObjectLifetimeTests.cc)
add_executable(Quine Quine.cc)
add_executable(RefCounter RefCounter.cc)

add_executable(LazyEvaluation LazyEvaluation.cc)
target_compile_features(LazyEvaluation PRIVATE cxx_std_20)