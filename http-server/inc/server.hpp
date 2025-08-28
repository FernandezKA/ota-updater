#pragma once

#include <boost/beast.hpp>
#include <atomic>
#include <functional>
#include <unordered_map>

namespace server {

namespace http = boost::beast::http;

class http_server {
public:
    http_server();
    
    void run_server();
    bool is_runned() const;
    void stop_server();

private:
    using request_handler = std::function<http::response<http::string_body>(
        const http::request<http::string_body>&)>;
    
    // Кастомная хеш-функция для пары (http::verb, std::string)
    struct key_hash {
        std::size_t operator()(const std::pair<http::verb, std::string>& k) const {
            std::size_t h1 = static_cast<std::size_t>(k.first);
            std::size_t h2 = std::hash<std::string>{}(k.second);
            return h1 ^ (h2 << 1);
        }
    };
    
    void register_handler(http::verb method, const std::string& path, request_handler handler);
    
    http::response<http::string_body> handle_request(
        const http::request<http::string_body>& request);
    
    http::response<http::string_body> handle_root(
        const http::request<http::string_body>& request);
    
    http::response<http::string_body> handle_upload(
        const http::request<http::string_body>& request);

    std::atomic<bool> is_run;
    std::unordered_map<std::pair<http::verb, std::string>, request_handler, key_hash> handlers;
};

} // namespace server
