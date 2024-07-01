#include "check_file.h"
#include <stdexcept>
#include <filesystem>

//Проверка аргументов командной строки
void CheckArgumentsAmount(int arguments_amount) {
    if (arguments_amount != 2) {
        throw std::invalid_argument("Invalid command line arguments amount: current - "
            + std::to_string(arguments_amount) + ", required - 2!");
    }
}

//Проверка пути 
void CheckInputPath(const std::filesystem::path& path_to_filesystem_object) {
    if (!std::filesystem::exists(path_to_filesystem_object)) {
        throw std::invalid_argument("Filesystem object by path " + path_to_filesystem_object.string() + " does not exist!");
    }
    if (!std::filesystem::is_regular_file(path_to_filesystem_object)) {
        throw std::invalid_argument("Filesystem object by path " + path_to_filesystem_object.string() + " is not a regular file!");
    }
    if (path_to_filesystem_object.extension() != ".json") {
        throw std::invalid_argument("Filesystem object by path " + path_to_filesystem_object.string() + " has an invalid extension!");
    }
}

//Проверка структуры JSON файла
bool IsJsonCorrect(const nlohmann::json& json) {
    try {
        if (json.contains("string_0") && json["string_0"].is_string() &&
            json.contains("number") && json["number"].is_number() &&
            json.contains("object") && json["object"].is_object() &&
            json["object"].contains("boolean") && json["object"]["boolean"].is_boolean() &&
            json["object"].contains("array") && json["object"]["array"].is_array() &&
            json.contains("string_1") && json["string_1"].is_null() &&
            json.contains("array") && json["array"].is_null()) {
            return true;
        }
    }
    catch (...) {
        return false;
    }
    return false;
}
