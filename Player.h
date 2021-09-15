//
// Created by Tr on 12.09.2021.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include "GenericPlayer.h"

/*
 *  3. Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4 метода:
 *              • virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса.
 *                  Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
 *              • void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
 *              • void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
 *              • void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.
 */

class Player : public GenericPlayer {
public:
    virtual bool IsHitting() const;
    void Win() const;
    void Lose() const;
    void Push() const;
};


#endif //OOP_PLAYER_H
