//
// Created by Tr on 08.09.2021.
//

#ifndef OOP_HAND_H
#define OOP_HAND_H

#include <vector>
#include "Card.h"

using namespace std;
/*
 * 3. Реализовать класс Hand, который представляет собой коллекцию карт.
 * В классе будет одно поле: вектор указателей карт (удобно использовать вектор, т.к. это по сути динамический массив,
 * а тип его элементов должен быть - указатель на объекты класса Card). Также в классе Hand должно быть 3 метода:
 *      • метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
 *      • метод Clear, который очищает руку от карт
 *      • метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11).
*/

class Hand {
private:
    vector<Card*> cardsInHand;
    int sumPoints;
    bool isAceOnHand;
public :
    Hand() : sumPoints(0), isAceOnHand(false) {}
    ~Hand() {}
    void add(const Card* newCard);
    void clear();
    int getValue() const;
};


#endif //OOP_HAND_H
