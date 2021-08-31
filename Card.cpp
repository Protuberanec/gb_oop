//
// Created by Tr on 31.08.2021.
//

#include "Card.h"

Card::Card() {
    status = FACE_UP;
}

SUIT Card::getSuit() const {
    return suit;
}

void Card::setSuit(SUIT suit) {
    Card::suit = suit;
}

CARD_VALUE Card::getValue() const {
    return value;
}

void Card::setValue(CARD_VALUE value) {
    Card::value = value;
}

bool Card::isStatus() const {
    return status;
}

void Card::setStatus(bool status) {
    Card::status = status;
}

Card::Card(SUIT suit, CARD_VALUE value, bool status) : suit(suit), value(value), status(status) {}

void Card::Flip() {
    status != status;

}
