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
        
        
        bitstream_loader::bitstream_loader(const std::string &bitstream_path) {

        }

        int bitstream_loader::load_bitstream() {
            return 0;
        }

        bool bitstream_loader::is_bitstream_loaded() const {
            return is_loaded;
        }
    }
 }