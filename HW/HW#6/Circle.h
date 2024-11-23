#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Shape.h"

class Circle : public Shape {
protected:
    void draw() override {
        std::cout << "¿ø" << std::endl;
    }
};

#endif
