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

#include <fstream>
#include <string>

#include <boost/filesystem.hpp>
#include <boost/noncopyable.hpp>

namespace driver {

namespace fpga_prog {

class fpga_manager : private boost::noncopyable {
public:
  explicit fpga_manager(const std::string &manager_name = "fpga0");

private:
  std::string_view m_bitstream_path;
  bool m_is_bitstream_loaded;

  std::string_view m_dts_overlay_path;
  bool m_is_dts_overlay_applied;
};
}; // namespace fpga_prog
}; // namespace driver