/**
 * @file updater.hpp
 * @author FernandezKA (i@kfernandes.ru)
 * @brief  firmware updater class.
 * @version 0.1
 * @date 2025-08-24
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

#include <cstdint>
#include <string_view>
#include <vector>

class updater {

  explicit updater(std::string_view path);
  ~updater() = default;

  int update_fpga();
  int update_boot();
  int update_rootfs();
};
