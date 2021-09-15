//
// Created by Tr on 12.09.2021.
//

#ifndef OOP_HOUSE_H
#define OOP_HOUSE_H

#include "GenericPlayer.h"
/*
 *     4. Реализовать класс House, который представляет дилера. Этот класс наследует от класса GenericPlayer. У него есть 2 метода:
 *          • virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. Если у дилера не больше 16 очков, то он берет еще одну карту.
 *          • void FlipFirstCard() - метод переворачивает первую карту дилера.
 */

class House : public GenericPlayer {
public:
    virtual bool IsHitting() const;
    void FlipFirstCard();

};


#endif //OOP_HOUSE_H
