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

#include <string>

namespace driver {
namespace fpga_prog {
class overlay_loader {
public:
  explicit overlay_loader(const std::string &overlay_path);
  ~overlay_loader() = default;

  int load_overlay();
  bool is_overlay_loaded() const;

private:
  std::string m_path;
  bool is_loaded = false;
};
} // namespace fpga_prog
} // namespace driver
