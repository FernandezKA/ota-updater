/**
 * @file bitstream_loader.hpp
 * @author FernandezKA (i@kfernandes.ru)
 * @brief
 * @version 0.1
 * @date 2025-08-09
 *
 * @copyright Copyright (c) 2025
 *
 */
 #pragma once

 #include "base_loader.hpp"

namespace driver {
namespace fpga_prog {

class bitstream_loader : public base_loader {
public:
  explicit bitstream_loader(std::string_view bitstream_path, std::string_view fpga_manager_path = FPGA_MANAGER_PATH);
  ~bitstream_loader() = default;


private:
  std::string m_path;
  bool m_is_loaded = false;

  static constexpr std::string_view FPGA_MANAGER_PATH = "/sys/class/fpga_manager/fpga0";
};

} // namespace fpga_prog
} // namespace driver
