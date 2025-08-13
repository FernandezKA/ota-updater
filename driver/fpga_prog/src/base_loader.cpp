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

 using namespace driver::fpga_prog;

 base_loader::base_loader(std::string_view path) : m_path(path), m_is_loaded(false) {

 }

 bool base_loader::is_loaded() const {
    return m_is_loaded;
 }

 int base_loader::load() {

    return 0;
 }

 int base_loader::load_async() {

    return 0;
 }

 int base_loader::remove() {

    if (m_path.empty()) {
        return -ENOENT;
    }

    boost::system::error_code error;

    if (boost::filesystem::exists(m_path)) {
        return (error.category() == boost::system::system_category()) ? (error.value()) : (EINVAL);
    }

    if (boost::filesystem::remove(m_path)) {
        return (error.category() == boost::system::system_category()) ? (error.value()) : (EINVAL);
    }

    return 0;
 }