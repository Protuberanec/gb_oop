//
// Created by Tr on 27.08.2021.
//

#include "PERSON.h"
PERSON::PERSON() {
    this->age = GENDER::MAN;
    this->name = "unknown";
    this->gender = 0;
    weight = 0;
}

PERSON::PERSON(const string& name, bool gender, unsigned short age) {
    this->age = age;
    this->name = name;
    this->gender = gender;
    weight = 0;
}

void PERSON::setName(const string &name) {
    PERSON::name = name;
}

const string &PERSON::getName() const {
    return name;
}

unsigned short PERSON::getWeight() const {
    return weight;
}

void PERSON::setWeight(unsigned short weight) {
    PERSON::weight = weight;
}

unsigned short PERSON::getAge() const {
    return age;
}

void PERSON::setAge(unsigned short age) {
    PERSON::age = age;
}

string PERSON::Gender() const {
    if (name == "unknown") {
        return "woman or man - no body know";
    }
    return (gender == GENDER::WOMAN ? "woman" : "man");
}
