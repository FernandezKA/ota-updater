cmake_minimum_required(VERSION 3.10)

project(OTA-updater
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(Boost_DEBUG ON)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)

find_package(Boost 1.66.0 REQUIRED COMPONENTS filesystem system program_options)

include_directories(
    ${CMAKE_SOURCE_DIR}/driver/fpga_prog/inc
    ${Boost_INCLUDE_DIRS}
)

set(SRC
    ./src/main.cpp
    ./src/security.cpp
    ./src/updater.cpp
)

add_executable(OtaUpdater ${SRC})

target_link_libraries(OtaUpdater PRIVATE 
    Boost::filesystem 
    Boost::system
    Boost::program_options
)

if(UNIX)
    target_link_libraries(OtaUpdater PRIVATE pthread)
endif()