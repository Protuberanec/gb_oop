//
// Created by Tr on 08.09.2021.
//

#include "Hand.h"

void Hand::add(const Card* newCard) {
    Card* temp = new Card(newCard);
    cardsInHand.push_back(temp);

    if (temp->getValue() == CARD_VALUE::ACE) {
        if (isAceOnHand == true) {
            ++sumPoints;
            return;
        }
        isAceOnHand = true;
    }
    sumPoints += static_cast<int>(newCard->getValue());
}

void Hand::clear() {
    if (cardsInHand.size() == 0) {
        return;
    }
    for(vector<Card*>::iterator el = cardsInHand.begin(); el != cardsInHand.end(); el++) {
        delete *el;
    }
    cardsInHand.clear();
    sumPoints = 0;
}

int Hand::getValue() const {
    return sumPoints;
}