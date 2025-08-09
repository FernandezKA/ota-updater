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
        overlay_loader::overlay_loader(const std::string& overlay_path) : m_path(overlay_path) {

        }

        int overlay_loader::load_overlay() {
         return 0;
        }

        bool overlay_loader::is_overlay_loaded() const {
         return false;
        }
    }
 }