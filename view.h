//
// Created by nether on 29.04.2020.
//

#pragma once
#include<memory.h>
#include<algorithm>
#include"shape.h"

/// @brief Класс обеспечивает отображение графических элементов на экране
class View {
public:
    explicit View(const ShapesVec& _shapes) : shapes(_shapes){};
    /// @brief метод отображения всего документа
    void update() {
        for (size_t idx = 0; idx < shapes.size(); idx++) {
            update(idx);
        }
    }
    /// @brief метод отображения отдельного элемента
    /// @param idx индекс отображаемого элемента
    void update(size_t idx) {
        shapes.at(idx)->draw();
    }
private:
    const ShapesVec& shapes;
};