//
// Created by nether on 29.04.2020.
//
#pragma once

#include<memory.h>
#include<algorithm>
#include "shape.h"

/// @brief Создание соответствующего объекта пр чтении из строки
std::unique_ptr<Shape> readType(std::string& source)
{
    std::cout << "read type from " << source << std::endl;
    source = ""; // Заглушка
    return std::make_unique<Circle>(); /// Заглушка
}

/// @brief Класс хранения документа
class Document {
public:
    explicit Document(const std::string& _name) : name(_name){}
    void saveDoc(const ShapesVec& vec) {
        std::string res;
        std::cout << "save to file" << std::endl;
        std::for_each(vec.cbegin(), vec.cend(), [&](const auto& a) {
            a->serialize(D_write, res);
        });
    }
    void readDoc(ShapesVec& vec) {
        std::cout << "read file" << std::endl;
        std::string res = "file";
        while(!res.empty()) {
            vec.push_back(readType(res));
            vec.back()->serialize(D_read, res);
        }
    }
private:
    const std::string& name;
};

