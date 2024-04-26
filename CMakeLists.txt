cmake_minimum_required(VERSION 3.0.0)
project(otus_cpp_prof VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(otus_cpp_prof main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
