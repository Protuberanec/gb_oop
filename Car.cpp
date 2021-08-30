//
// Created by Tr on 30.08.2021.
//

#include "Car.h"

Car::Car() {
    cout << "constructor Car" << endl;
}

PassengerCar::PassengerCar() : Car() {
    cout << "constructor PassengerCar" << endl;
}

Bus::Bus() : Car() {
    cout << "constructor Bus" << endl;
}

Minivan::Minivan() : PassengerCar(), Bus(), Car() {
    cout << "constructor Minivan" << endl;
}
