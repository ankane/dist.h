cmake_minimum_required(VERSION 3.18)

project(dist VERSION 0.3.0 LANGUAGES C)

include(GNUInstallDirs)

add_library(dist INTERFACE)
add_library(dist::dist ALIAS dist)

target_include_directories(
    dist
    INTERFACE
    "${PROJECT_SOURCE_DIR}/include/"
)

install(
    DIRECTORY "${PROJECT_SOURCE_DIR}/include/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)
