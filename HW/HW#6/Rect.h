#ifndef RECT_H
#define RECT_H

#include <iostream>
#include "Shape.h"

class Rect : public Shape {
protected:
    void draw() override {
        std::cout << "�簢��" << std::endl;
    }
};

#endif
