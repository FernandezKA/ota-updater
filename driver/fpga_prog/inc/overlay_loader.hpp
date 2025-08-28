/**
 * @file overlay_loader.hpp
 * @author FernandezKA (i@kfernandes.ru)
 * @brief  overlay loader for Zynq FpgaManager
 * @version 0.1
 * @date 2025-08-07
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once

#include <string>
#include "base_loader.hpp"


namespace driver {
namespace fpga_prog {
class overlay_loader : public base_loader {
public:
  explicit overlay_loader(std::string_view overlay_path, std::string_view overlay_configfs_path = "configfs");
  ~overlay_loader() = default;

  int load_overlay();
  bool is_overlay_loaded() const;
  int remove();

private:
  std::string m_path;
  bool is_loaded = false;
};
} // namespace fpga_prog
} // namespace driver
