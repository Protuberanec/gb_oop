//
// Created by Tr on 27.08.2021.
//

#ifndef OOP_FRUIT_H
#define OOP_FRUIT_H

#include <string>

using namespace std;

using Fruit = class FRUIT;
using Apple = class APPLE;
using Banana = class BANANA;
using GrannySmith = class GRANNY_SMITH;

class FRUIT {
private:
    string name;
    string color;

public:
    FRUIT();

    FRUIT(const string &name, const string &color);

    const string &getName() const;
    void setName(const string &name);

    const string &getColor() const;
    void setColor(const string &color);
};


class APPLE : public FRUIT {
public:
    APPLE();
    APPLE(string color);
};

class BANANA : public FRUIT {
public:
    BANANA();
};

class GRANNY_SMITH : public APPLE {
public:
    GRANNY_SMITH();
};


#endif //OOP_FRUIT_H
