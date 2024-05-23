cmake_minimum_required(VERSION 3.0.0)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.1.${PATCH_VERSION})

project(otus_ip_filter VERSION 0.1.0 LANGUAGES C CXX)

configure_file(version.h.in version.h)

# include(CTest)
# enable_testing()

add_executable(otus_ip_filter main.cpp)

target_include_directories(otus_ip_filter
    PRIVATE "${CMAKE_BINARY_DIR}"
)

if (MSVC)
    target_compile_options(otus_ip_filter PRIVATE
        /W4
    )
    # target_compile_options(otus_ip_filter PRIVATE
    #     /W4
    # )
    # target_compile_options(test_version PRIVATE
    #     /W4
    # )
else ()
    target_compile_options(otus_ip_filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    # target_compile_options(otus_ip_filter PRIVATE
    #     -Wall -Wextra -pedantic -Werror
    # )
    # target_compile_options(test_version PRIVATE
    #     -Wall -Wextra -pedantic -Werror
    # )
endif()

set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(INSTALL_GMOCK OFF CACHE BOOL "" FORCE)

install(TARGETS otus_ip_filter RUNTIME DESTINATION bin)

set(CPACK_PACKAGE_NAME otus_ip_filter)
set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PATCH_VERSION}")

set(CPACK_PACKAGE_CONTACT no@bk.ru)

include(CPack)
