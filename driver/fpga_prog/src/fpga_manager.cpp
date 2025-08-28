/**
 * @file fpga_manager.cpp
 * @author FernandezKA (i@kfernandes.ru)
 * @brief 
 * @version 0.1
 * @date 2025-08-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <fpga_manager.hpp>
 #include <bitstream_loader.hpp>
 #include <overlay_loader.hpp>

namespace driver{
    namespace fpga_prog{
        
        fpga_manager::fpga_manager(std::string_view bitstream_path, std::string_view overlay_path) : 
            ovl_loader(std::make_unique<overlay_loader>(overlay_path)), 
            bts_loader(std::make_unique<bitstream_loader>(bitstream_path))
        {

        };
    }
}
