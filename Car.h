//
// Created by Tr on 30.08.2021.
//

#ifndef OOP_CAR_H
#define OOP_CAR_H

#include <string>
#include <iostream>
using namespace std;


/*
 * 2. Создать класс Car (автомобиль) с полями company (компания) и model (модель).
 * Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус).
 * От этих классов наследует класс Minivan (минивэн).
 * Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.
 * Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы.
 * Обратить внимание на проблему «алмаз смерти».
 */
class Car {
protected:
    string companyName;
    string model;
public:
    Car();
};

class PassengerCar : virtual public Car {
public:
    PassengerCar();
};

class Bus : virtual public Car {
public:
    Bus();
};
/*елси в базовых классах не объявлять классы как virtual...
 * то самый базовый класс Car будет создаваться два раза... для PassengerCar, и Bus...*/
class Minivan : public PassengerCar, public Bus {
public:
    Minivan();
};

#endif //OOP_CAR_H
