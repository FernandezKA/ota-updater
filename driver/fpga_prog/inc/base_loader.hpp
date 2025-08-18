 /**
 * @file base_loader.hpp
* @author FernandezKA (i@kfernandes.ru)
 * @brief Base loader for files
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */
 #pragma once

 #include <string_view>
 #include <functional>
 #include <filesystem>

 #include <boost/filesystem.hpp>
 #include <boost/system/error_code.hpp>
 #include <cerrno>

 namespace driver {
    namespace fpga_prog{
        class base_loader {
            private:
            std::string_view m_path_src;
            std::string_view m_path_dest;
            bool m_is_loaded;
            std::function<void(void)> m_callback;
            public:
            explicit base_loader(std::string_view m_path_src, std::string_view m_path_dest);
            virtual ~base_loader() = default;

            virtual int load();
            virtual int remove();
            virtual bool is_loaded() const;
        };
    }
 }