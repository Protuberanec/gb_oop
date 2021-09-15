//
// Created by Tr on 31.08.2021.
//

#ifndef OOP_CARD_H
#define OOP_CARD_H

#include <iostream>

using namespace std;


 /*
  * 4. Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три поля:
  * масть, значение карты и положение карты (вверх лицом или рубашкой).
  * Сделать поля масть и значение карты типом перечисления (enum). Положение карты - тип bool.
  * Также в этом классе должно быть два метода:
  *         • метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх,
  *           то он ее поворачивает лицом вверх, и наоборот.
  *         • метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
*/

#define FACE_UP false
#define FACE_DOWN   true

enum class SUIT {
    SPADES = 0,
    CLUBS = 1,
    DIAMONDS = 2,
    HEARTS = 3,
};

enum class CARD_VALUE {
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 2,
    QUEEN = 3,
    KING = 4,
    ACE = 11,
    JOKER = 15,
};

class Card {
private:
    SUIT m_Suit;
    CARD_VALUE m_Rank;
    bool m_IsFaceUp;    //face up, face down
public:
    Card();
    Card(const Card* other);

    Card(SUIT suit, CARD_VALUE value, bool status);

    SUIT getSuit() const;
    void setSuit(SUIT suit);
    CARD_VALUE getValue() const;
    void setValue(CARD_VALUE value);
    bool isStatus() const;
    void setStatus(bool status);

    void Flip();

    friend ostream& operator<<(ostream& os, const Card& aCard);
};





#endif //OOP_CARD_H
