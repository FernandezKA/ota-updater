/**
 * @file bitstream_loader.cpp
 * @author FernandezKA (i@kfernandes.ru)
 * @brief 
 * @version 0.1
 * @date 2025-08-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <fpga_manager.hpp>


 namespace driver {
    namespace fpga_prog {
        
        
        bitstream_loader::bitstream_loader(std::string_view bitstream_path, std::string_view fpga_manager_path) : 
            base_loader(bitstream_path, fpga_manager_path) {

        }

        

    }
 }