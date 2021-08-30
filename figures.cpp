//
// Created by Tr on 30.08.2021.
//

#include "figures.h"

Parallelogram::Parallelogram() : a(0), b(0) { }

Parallelogram::Parallelogram(float _a, float _b, float _angle) : a(_a), b(_b), angle(_angle) { }

float Parallelogram::area() const {
    cout << "parallelogram square : ";
    return a * b * sin(angle * M_PI / 180);
}

Rectangle::Rectangle() : Parallelogram() {}

Rectangle::Rectangle(float _a, float _b) : Parallelogram(_a, _b, 0) { }

float Rectangle::area() const {
    cout << "rectangle square : ";
    return a*b;
}

Square::Square() : Parallelogram() {}

Square::Square(float a) : Parallelogram(a, 0, 0) { }

float Square::area() const {
    cout << "square square : ";
    return a*a;
}

Rhombus::Rhombus() : Parallelogram(0,0,0) {}

Rhombus::Rhombus(float d1, float d2) : Parallelogram(d1,d2,0) {}

float Rhombus::area() const {
    cout << "rhombus square : ";
    return (a*b)/2; //a - d1, b - d2
}

Circle::Circle() : r(0) {}

Circle::Circle(int _r) : r(_r){ }

float Circle::area() const {
    cout << "circle square : ";
    return M_PI * r * r;
}
