include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(helloworld_cli_test tests.cpp)

target_include_directories(
  helloworld_cli_test 
  PUBLIC 
  ${CMAKE_SOURCE_DIR} 
)
target_link_libraries(helloworld_cli_test PUBLIC gtest gtest_main)
target_link_libraries(helloworld_cli_test PRIVATE
    helloworld
)
