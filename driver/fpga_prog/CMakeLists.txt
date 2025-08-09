cmake_minimum_required(VERSION 3.11)

project(fpga_prog)

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

include_directories(./inc)

add_library(fpga_prog ${SOURCES} ${INCLUDES})