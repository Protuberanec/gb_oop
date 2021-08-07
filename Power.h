//
// Created by Tr on 07.08.2021.
//

#ifndef OOP_POWER_H
#define OOP_POWER_H

#include <math.h>

//1. Создать класс Power, который содержит два вещественных числа. Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел.
//Еще создать два метода: один с именем set, который позволит присваивать значения переменным, второй — calculate, который
//будет выводить результат возведения первого числа в степень второго числа. Задать значения этих двух чисел по умолчанию.

class Power {
private :
    double base;
    double power;
public:
    Power();
    Power(int _a, int _b);

    double getBase() const;
    void setBase(double a);
    double getPower() const;
    void setPower(double b);

    double calculate() const;
};


#endif //OOP_POWER_H
