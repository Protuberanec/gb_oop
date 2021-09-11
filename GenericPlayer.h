//
// Created by Tr on 11.09.2021.
//

#ifndef OOP_GENERICPLAYER_H
#define OOP_GENERICPLAYER_H

#include <string>
#include <iostream>

#include "Hand.h"

/*
 * 4. Согласно иерархии классов, которая представлена в методичке к уроку 3,
 * от класса Hand наследует класс GenericPlayer, который обобщенно представляет игрока,
 * ведь у нас будет два типа игроков - человек и компьютер.
 * Создать класс GenericPlayer, в который добавить поле name - имя игрока. Также добавить 3 метода:
 *          • IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
 *          • IsBoosted() - возвращает bool значение, есть ли у игрока перебор
 *          • Bust() - выводит на экран имя игрока и объявляет, что у него перебор.
 */

class GenericPlayer : public Hand {
private:
    std::string name;
public:
    virtual bool IsHitting() = 0;
    bool IsBoosted();
    void Bust();
};


#endif //OOP_GENERICPLAYER_H
