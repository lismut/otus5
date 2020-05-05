//
// Created by nether on 29.04.2020.
//
#pragma once
#include<iostream>
#include<memory>

/// @brief Направление сериализации элемента
enum TDirection {
    D_read, ///< чтение из строки
    D_write ///< сохранение в строку
};

/// @brief Абстрактный класс для гравических элементов
struct Shape {
public:
    virtual void draw() = 0;
    virtual void serialize(TDirection dir, std::string& contains) = 0;
};

typedef std::vector<std::unique_ptr<Shape>> ShapesVec;

/// @brief Класс для хранения окружности
struct Circle : public Shape {
public:
    void draw() final {
        std::cout << "draw circle" << std::endl;
    };
    void serialize(TDirection dir, std::string& contains) final {
        switch(dir) {
            case D_read:
                std::cout << "read circle" << contains << std::endl;
                break;
            case D_write:
                std::cout << "write circle" << contains << std::endl;
        }
    }
};

/// @brief Класс для хранения точки
struct Point : public Shape {
public:
    void draw() final {
        std::cout << "draw point" << std::endl;
    };
    void serialize(TDirection dir, std::string& contains) final {
        switch(dir) {
            case D_read:
                std::cout << "read point" << contains << std::endl;
                break;
            case D_write:
                std::cout << "write point" << contains << std::endl;
        }
    }
};

/// @brief Класс для хранения квадрата
struct Square : public Shape {
public:
    void draw() final {
        std::cout << "draw square" << std::endl;
    };
    void serialize(TDirection dir, std::string& contains) final {
        switch(dir) {
            case D_read:
                std::cout << "read square" << contains << std::endl;
                break;
            case D_write:
                std::cout << "write square" << contains << std::endl;
        }
    }
};
