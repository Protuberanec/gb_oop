//
// Created by Tr on 27.08.2021.
//

#include "fruit.h"

const string &FRUIT::getName() const {
    return name;
}

void FRUIT::setName(const string &name) {
    FRUIT::name = name;
}

const string &FRUIT::getColor() const {
    return color;
}

void FRUIT::setColor(const string &color) {
    FRUIT::color = color;
}

FRUIT::FRUIT(const string &name, const string &color) : name(name), color(color) {

}

FRUIT::FRUIT() {
    name = "unknown";
    color = "黑排泄物色";
}

APPLE::APPLE() : FRUIT("apple", "green"){ }
APPLE::APPLE(string color) : FRUIT("apple", color){ }

BANANA::BANANA() : FRUIT("banana", "yellow") {}

GRANNY_SMITH::GRANNY_SMITH() {
    setName("Granny Smith apple");
}
