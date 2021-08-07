//
// Created by Tr on 07.08.2021.
//

#include "Power.h"

Power::Power()  : base(0), power(0) {}

Power::Power(int _a, int _b) : base(_a), power(_b) {}

double Power::getBase() const {
    return base;
}

void Power::setBase(double a) {
    Power::base = a;
}

double Power::getPower() const {
    return power;
}

void Power::setPower(double b) {
    Power::power = b;
}

double Power::calculate() const {
    return pow(base, power);
}


