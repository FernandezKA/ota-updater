/**
 * @file main.cpp
 * @author FernandezKA (i@kfernandes.ru)
 * @brief 
 * @version 0.1
 * @date 2025-07-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <string>
#include <boost/program_options.hpp>

#include "../http-server/inc/server.hpp"
#include <thread>

 namespace po = boost::program_options;

 int main(int argc, char *argv[]) {

   po::options_description desc("Allowed options");
   desc.add_options()
      ("help", "produce help message");

    po::variables_map vm;
    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);
    } catch (const po::error& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 0;
    }


        server::http_server server;
    
    std::thread server_thread([&server]() {
        server.run_server();
    });
    
    std::cout << "Server started. Press Enter to stop..." << std::endl;
    std::cin.get();
    
    server.stop_server();
    if (server_thread.joinable()) {
        server_thread.join();
    }
    
    std::cout << "Server stopped." << std::endl;

    

    return 0;
 }