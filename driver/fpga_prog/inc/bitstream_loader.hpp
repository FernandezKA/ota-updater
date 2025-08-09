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

namespace driver {
namespace fpga_prog {

class bitstream_loader {
public:
  explicit bitstream_loader(const std::string &bitstream_path);
  ~bitstream_loader() = default;

  int load_bitstream();
  bool is_bitstream_loaded() const;

private:
  std::string m_path;
  bool is_loaded = false;
};

} // namespace fpga_prog
} // namespace driver
