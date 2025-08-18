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
  explicit bitstream_loader(std::string_view m_bitstream_path);
  ~bitstream_loader() = default;

  int load();
  bool is_loaded() const;

private:
  std::string m_path;
  bool m_is_loaded = false;

  std::string_view fpga_manager_path = "/sys/class/fpga_manager/fpga0";
};

} // namespace fpga_prog
} // namespace driver
