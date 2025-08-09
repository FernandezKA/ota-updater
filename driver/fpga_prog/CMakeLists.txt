cmake_minimum_required(VERSION 3.11)
project(fpga_prog)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(MAKE_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

set(INCLUDES
    ./inc/bitstream_loader.hpp
    ./inc/fpga_manager.hpp
    ./inc/overlay_loader.hpp    
)

set(SOURCES
    ./src/bitstream_loader.cpp
    ./src/fpga_manager.cpp
    ./src/overlay_loader.cpp   
)

include_directories(inc)

add_library(fpga_prog ${SOURCES} ${INCLUDES})

set_target_properties(fpga_prog PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)