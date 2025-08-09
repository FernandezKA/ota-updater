cmake_minimum_required(VERSION 3.10)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR "In-source builds are not allowed. Please create a separate build directory.")
endif()

project(OTA-updater
    VERSION 1.0
    LANGUAGES CXX)

get_filename_component(PROJECT_ROOT_DIR ${CMAKE_SOURCE_DIR} DIRECTORY)
message(STATUS "Project root: ${PROJECT_ROOT_DIR}")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
file(MAKE_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
file(MAKE_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(Boost_DEBUG OFF)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)

cmake_policy(SET CMP0167 NEW)

find_package(Boost 1.66.0 REQUIRED COMPONENTS filesystem system program_options)

set(SRC
    src/main.cpp
    src/security.cpp
    src/updater.cpp
)

add_executable(OtaUpdater ${SRC})

add_subdirectory(
    ${PROJECT_ROOT_DIR}/driver/fpga_prog
    ${CMAKE_BINARY_DIR}/driver/fpga_prog
)

target_include_directories(OtaUpdater PRIVATE
    ${PROJECT_ROOT_DIR}/driver/fpga_prog/inc
    ${Boost_INCLUDE_DIRS}
)

target_link_libraries(OtaUpdater PRIVATE 
    Boost::filesystem 
    Boost::system
    Boost::program_options
    fpga_prog
)

if(UNIX)
    target_link_libraries(OtaUpdater PRIVATE pthread)
endif()

set_target_properties(OtaUpdater PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)