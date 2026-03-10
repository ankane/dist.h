cmake_minimum_required(VERSION 3.18)

project(dist VERSION 0.3.1 LANGUAGES C)

include(GNUInstallDirs)

add_library(dist INTERFACE)
add_library(dist::dist ALIAS dist)

target_link_libraries(dist INTERFACE m)

target_include_directories(
    dist
    INTERFACE
    "${PROJECT_SOURCE_DIR}/include/"
)

install(
    DIRECTORY "${PROJECT_SOURCE_DIR}/include/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    option(BUILD_TESTING "" ON)
    option(BUILD_EXAMPLE "" ON)

    if(BUILD_TESTING)
        add_executable(test test/main.c)
        target_link_libraries(test PRIVATE dist::dist)
        if(NOT MSVC)
            target_compile_options(test PRIVATE -Wall -Wextra -Wpedantic -Werror)
        endif()
    endif()

    if(BUILD_EXAMPLE)
        add_executable(example example/main.c)
        target_link_libraries(example PRIVATE dist::dist)
    endif()
endif()
