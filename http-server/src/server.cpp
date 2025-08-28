/**
 * @file server.cpp
 * @author FernandezKA (i@kfernandes.ru)
 * @brief HTTP server for uploading firmware
 * @version 0.1
 * @date 2025-08-28
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "server.hpp"
#include <atomic>
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <fstream>
#include <iostream>
#include <mutex>
#include <thread>
#include <unordered_map>
#include <functional>

namespace server {

using tcp = boost::asio::ip::tcp;
namespace http = boost::beast::http;

const std::string ROOT_HTML = R"(
<!DOCTYPE html>
<html>
<head>
    <title>OTA Updater</title>
    <meta charset="UTF-8">
    <style>
        body { font-family: Arial, sans-serif; margin: 40px; }
        h1 { color: #333; }
        form { margin: 20px 0; padding: 20px; border: 1px solid #ccc; border-radius: 5px; }
        input[type="file"] { margin: 10px 0; }
        input[type="submit"] { background-color: #4CAF50; color: white; padding: 10px 15px; border: none; border-radius: 4px; cursor: pointer; }
        input[type="submit"]:hover { background-color: #45a049; }
    </style>
</head>
<body>
    <h1>Обновление прошивки Zynq SoC</h1>
    <form action="/upload" method="post" enctype="multipart/form-data">
        <label for="file">Выберите файл для загрузки:</label><br>
        <input type="file" id="file" name="file" required><br><br>
        <input type="submit" value="Загрузить файл">
    </form>
</body>
</html>
)";

http_server::http_server() : is_run(false) {
    // Регистрация обработчиков запросов
    register_handler(http::verb::get, "/", 
        [this](const http::request<http::string_body>& req) {
            return handle_root(req);
        });
    
    register_handler(http::verb::post, "/upload", 
        [this](const http::request<http::string_body>& req) {
            return handle_upload(req);
        });
}

void http_server::register_handler(
    http::verb method, 
    const std::string& path, 
    request_handler handler
) {
    handlers[{method, path}] = std::move(handler);
}

http::response<http::string_body> http_server::handle_root(
    const http::request<http::string_body>& request
) {
    http::response<http::string_body> response;
    response.result(http::status::ok);
    response.set(http::field::content_type, "text/html");
    response.body() = ROOT_HTML;
    response.prepare_payload();
    return response;
}

http::response<http::string_body> http_server::handle_upload(
    const http::request<http::string_body>& request
) {
    std::ofstream file("uploaded_firmware.bin", std::ios::binary);
    if (!file) {
        throw std::runtime_error("Failed to create file");
    }

    file.write(request.body().data(), request.body().size());
    file.close();

    http::response<http::string_body> response;
    response.result(http::status::ok);
    response.set(http::field::content_type, "text/plain");
    response.body() = "File uploaded successfully";
    response.prepare_payload();
    return response;
}

http::response<http::string_body> http_server::handle_request(
    const http::request<http::string_body>& request
) {
    auto key = std::make_pair(request.method(), request.target());
    auto it = handlers.find(key);
    
    if (it != handlers.end()) {
        return it->second(request);
    }

    // Обработка неизвестных запросов
    http::response<http::string_body> response;
    response.result(http::status::not_found);
    response.set(http::field::content_type, "text/plain");
    response.body() = "Not Found";
    response.prepare_payload();
    return response;
}

void http_server::run_server() {
    if (is_run.exchange(true)) {
        return;
    }

    try {
        boost::asio::io_context io_context;
        tcp::acceptor acceptor(io_context, {tcp::v4(), 8080});

        while (is_run) {
            tcp::socket socket(io_context);
            acceptor.accept(socket);

            // Чтение запроса
            boost::beast::flat_buffer buffer;
            http::request<http::string_body> request;
            http::read(socket, buffer, request);

            // Обработка запроса и отправка ответа
            http::response<http::string_body> response;
            try {
                response = handle_request(request);
            } catch (const std::exception& e) {
                response.result(http::status::internal_server_error);
                response.set(http::field::content_type, "text/plain");
                response.body() = std::string("Error: ") + e.what();
                response.prepare_payload();
            }

            http::write(socket, response);
            socket.shutdown(tcp::socket::shutdown_send);
        }
    } catch (const std::exception& e) {
        std::cerr << "Server exception: " << e.what() << std::endl;
        is_run = false;
    }
}

bool http_server::is_runned() const { 
    return is_run.load(); 
}

void http_server::stop_server() { 
    is_run = false; 
}

} // namespace server
