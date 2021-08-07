//
// Created by Tr on 07.08.2021.
//

#ifndef OOP_RGBA_H
#define OOP_RGBA_H
#include <iostream>
#include <cstdint>

using namespace std;

/*
    2. Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t:
    m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу).
    Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha.
    Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения
    для m_red, m_blue, m_green и m_alpha. Написать функцию print(), которая будет выводить значения переменных-членов.
*/

class RGBA {
private:
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;
public:
    RGBA();

    RGBA(uint8_t mRed, uint8_t mGreen, uint8_t mBlue, uint8_t mAlpha);

    void print() const;
};


#endif //OOP_RGBA_H
