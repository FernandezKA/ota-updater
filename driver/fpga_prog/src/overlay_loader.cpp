/**
 * @file overlay_loader.cpp
 * @author FernandezKA (i@kfernandes.ru)
 * @brief  overlay loader for Zynq FpgaManager
 * @version 0.1
 * @date 2025-08-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <overlay_loader.hpp>


 namespace driver {
    namespace fpga_prog{
        overlay_loader::overlay_loader(std::string_view overlay_path, std::string_view overlay_configfs_path) : 
            base_loader(overlay_path, overlay_configfs_path) {

        }
    }
 }