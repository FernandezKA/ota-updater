/**
 * @file base_loader.cpp
 * @author FernandezKA (i@kfernandes.ru)
 * @brief  base loader implementation
 * @version 0.1
 * @date 2025-08-13
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "base_loader.hpp"
#include <fstream>

using namespace driver::fpga_prog;

namespace fs = boost::filesystem;

base_loader::base_loader(std::string_view path_src, std::string_view path_dest)
    : m_path_src(path_src), m_path_dest(path_dest), m_is_loaded(false) {}

bool base_loader::is_loaded() const { return m_is_loaded; }

int base_loader::load() {
  fs::path file_path(m_path_dest);

  std::ofstream file(file_path, std::ios::binary | std::ios::trunc);
  if (file.is_open()) {
    throw std::runtime_error("Failed to open file: " + file_path.string());
  }

  return 0;
}

int base_loader::remove() {

  if (m_path_dest.empty()) {
    return -ENOENT;
  }

  boost::system::error_code error;

  if (boost::filesystem::exists(m_path_dest)) {
    return (error.category() == boost::system::system_category())
               ? (error.value())
               : (EINVAL);
  }

  if (boost::filesystem::remove(m_path_dest)) {
    return (error.category() == boost::system::system_category())
               ? (error.value())
               : (EINVAL);
  }

  return 0;
}