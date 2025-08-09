/**
 * @file fpga_manager.hpp
 * @author FernandezKA (i@kfernandes.ru)
 * @brief  fpga manager for Xilinx Zynq SoC
 * @version 0.1
 * @date 2025-07-24
 *
 * @copyright Copyright (c) 2025
 *
 */
 #pragma once

#include <fstream>
#include <string>
#include <memory>

#include <overlay_loader.hpp>
#include <bitstream_loader.hpp>
#include <fpga_manager.hpp>

namespace driver {

namespace fpga_prog {

class fpga_manager {
public:
  explicit fpga_manager(const std::string& bitstream_path, const std::string& overlay_path);

private:
  std::unique_ptr<overlay_loader> ovl_loader = nullptr;
  std::unique_ptr<bitstream_loader> bts_loader = nullptr;

};
}; // namespace fpga_prog
}; // namespace driver
