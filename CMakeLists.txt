cmake_minimum_required(VERSION 3.28)

project(dumbcloud VERSION 0.0.1 LANGUAGES CXX)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX
        ${CMAKE_CURRENT_BINARY_DIR}/install
        CACHE STRING "" FORCE)
else()
    message(STATUS "why the fuck you are FALSE")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(cmake_include_current_dir ON)

message(STATUS "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
message("PLATFORM = ${CMAKE_VS_PLATFORM_NAME_DEFAULT}")


add_subdirectory(dumbcloud_utils)
add_subdirectory(dumbcloud_server)
add_subdirectory(dumbcloud_client)
add_subdirectory(dumbcloud_gui)