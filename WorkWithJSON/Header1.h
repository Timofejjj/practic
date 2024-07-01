#ifndef CHECK_FILE_H
#define CHECK_FILE_H

#include <filesystem>
#include "json.hpp"

//Проверка количества аргументов
void CheckArgumentsAmount(int arguments_amount);

//КОрректоность пути
void CheckInputPath(const std::filesystem::path& path_to_filesystem_object);

//Корректность JSON структуры
bool IsJsonCorrect(const nlohmann::json& json);

#endif // CHECK_FILE_H
