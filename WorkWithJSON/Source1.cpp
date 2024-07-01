#include "check_file.h"
#include "json.hpp"
#include <iostream>
#include <fstream>


int main(int argc, char* argv[]) {
    try {
        CheckArgumentsAmount(argc);

        std::filesystem::path json_path = argv[1];
        CheckInputPath(json_path);

        std::ifstream json_file(json_path);

        //Обработка открытия
        if (!json_file.is_open()) {
            throw std::runtime_error("Unable to open JSON file.");
        }

        nlohmann::json json_data;
        json_file >> json_data;
        
        //Обработка корректности JSON
        if (IsJsonCorrect(json_data)) {
            std::cout << "Structure of JSON-file by path " << json_path << " is correct." << std::endl;
        }
        else {
            std::cout << "Structure of JSON-file by path " << json_path << " is incorrect." << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

