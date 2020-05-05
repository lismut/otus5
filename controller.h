//
// Created by nether on 29.04.2020.
//
#pragma once
#include<vector>
#include"view.h"
#include"document.h"



/// @brief Класс-контроллер для взаимодействия хранения графических объектов и операций над ними
class Controller {
public:
    Controller() : view(shapes){}
    template<typename T>
    void makeShape() {
        shapes.push_back(std::make_unique<T>());
        view.update(shapes.size() - 1);
    }
    void removeShape(size_t idx) {
        shapes.erase(shapes.begin() + idx);
        std::cout << "remove figure " << idx << std::endl;
        view.update();
    }

    void saveDoc(const std::string& _name) {
        name = _name;
        saveDoc();
    }
    void saveDoc() const {
        Document doc(name);
        doc.saveDoc(shapes);
    }
    void readDoc(const std::string& _name) {
        name = _name;
        Document doc(name);
        doc.readDoc(shapes);
        view.update();
    }
private:
    template<typename T>
    void foreach(const T& func) {
        std::for_each(shapes.begin(), shapes.end(), func);
    }
    ShapesVec shapes;
    View view;
    std::string name;
};