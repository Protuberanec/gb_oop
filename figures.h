//
// Created by Tr on 30.08.2021.
//

#ifndef OOP_FIGURES_H
#define OOP_FIGURES_H
#include <math.h>
#include <iostream>

using namespace std;

/*
 * 1. Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг).
 * Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб).
 * Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь).
 * Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
 */

class Figure {
public:
    virtual float area() const = 0;
};

class Parallelogram : public Figure {
protected:
    float a;
    float b;
    float angle;    //between a and b
public:
    Parallelogram();
    Parallelogram(float _a, float _b, float _angle);
    float area() const;
};

class Rectangle : public Parallelogram {
public :
    Rectangle();
    Rectangle(float _a, float _b);
    float area() const;
};

class Square : public Parallelogram {
public:
    Square();
    Square(float a);
    float area() const;
};

class Rhombus : public Parallelogram {
public:
    Rhombus();
    Rhombus(float d1, float d2);
    float area() const;
};

class Circle : public Figure {
    float  r;
public:
    Circle();
    Circle(int _r);
    float area() const;
};


#endif //OOP_FIGURES_H
