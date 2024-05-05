cmake_minimum_required(VERSION 3.0.0)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.1.${PATCH_VERSION})

project(prof_hw1 VERSION 0.1.0 LANGUAGES C CXX)

configure_file(version.h.in version.h)

# include(CTest)
# enable_testing()

add_executable(helloworld_cli main.cpp)
add_library(helloworld lib.cpp)
#add_executable(test_version test_version.cpp)

set_target_properties(helloworld_cli helloworld PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(helloworld
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(helloworld_cli PRIVATE
    helloworld
)

if (MSVC)
    target_compile_options(helloworld_cli PRIVATE
        /W4
    )
    target_compile_options(helloworld PRIVATE
        /W4
    )
    # target_compile_options(test_version PRIVATE
    #     /W4
    # )
else ()
    target_compile_options(helloworld_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(helloworld PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    # target_compile_options(test_version PRIVATE
    #     -Wall -Wextra -pedantic -Werror
    # )
endif()

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_PACKAGE_NAME helloworld)
set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PATCH_VERSION}")

set(CPACK_PACKAGE_CONTACT no@bk.ru)

include(CPack)
