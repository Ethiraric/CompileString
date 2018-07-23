cmake_minimum_required(VERSION 2.6)

#configuration
project(CompileString)

#sources files
set(SRCS
  main.cpp
  test.cpp
)

#binary
add_executable(compilestring_tests ${SRCS})
target_include_directories(compilestring_tests PRIVATE .)
target_link_libraries(compilestring_tests CompileString)
add_test(NAME compilestring_tests COMMAND compilestring_tests)
