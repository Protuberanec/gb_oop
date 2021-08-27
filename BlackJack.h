//
// Created by Tr on 27.08.2021.
//

#ifndef OOP_BLACKJACK_H
#define OOP_BLACKJACK_H

#include <list>

using namespace std;

/*
 * 3. Изучить правила игры в Blackjack. Подумать, как написать данную игру на С++, используя объектно-ориентированное программирование.
 * Сколько будет классов в программе? Какие классы будут базовыми, а какие производными?
 * Продумать реализацию игры с помощью классов и записать результаты.
 */

/*      обычная игра в очка со стероидами.....
 *
 *
 */

enum CARDS {
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 11,
    QUEEN = 12,
    KING = 13,
    ACE = 14,
    JOKER = 15,
};

enum SUIT {
    SPADES = 0,
    CLUBS = 1,
    DIAMONDS = 2,
    HEARTS = 3,
};

using cardType = int;
using suit = int;

/* карты в колоде */
class DeckCards {
private:
    list<pair<suit, cardType>> deck;
public:
    int shuffle();
    int getCard();
};

class CardsOnHand {

};

/* игрок и казино*/
class Player : public CardsOnHand {

};

class GamePlay {
private:
    DeckCards deck;

    list<Player> players;
    Player casino;
public:

};

#endif //OOP_BLACKJACK_H
