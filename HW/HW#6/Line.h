#ifndef LINE_H
#define LINE_H

#include <iostream>
#include "Shape.h"

class Line : public Shape {
protected:
    void draw() override {
        std::cout << "¼±" << std::endl;
    }
};

#endif
