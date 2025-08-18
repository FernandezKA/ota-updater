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

    

    return 0;
 }