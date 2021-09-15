//
// Created by Tr on 31.08.2021.
//

#include "Card.h"

ostream& operator<<(ostream& os, const Card& aCard)
{
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    const string SUITS[] = { "c", "d", "h", "s" };

    if (aCard.m_IsFaceUp)
    {
        os << RANKS[static_cast<int>(aCard.m_Rank)] << SUITS[static_cast<int>(aCard.m_Suit)];
    }
    else
    {
        os << "face down";
    }

    return os;
}

Card::Card() {
    m_IsFaceUp = FACE_UP;
}

SUIT Card::getSuit() const {
    return m_Suit;
}

void Card::setSuit(SUIT suit) {
    Card::m_Suit = suit;
}

CARD_VALUE Card::getValue() const {
    return m_Rank;
}

void Card::setValue(CARD_VALUE value) {
    Card::m_Rank = value;
}

bool Card::isStatus() const {
    return m_IsFaceUp;
}

void Card::setStatus(bool status) {
    Card::m_IsFaceUp = status;
}

Card::Card(SUIT suit, CARD_VALUE value, bool status) : m_Suit(suit), m_Rank(value), m_IsFaceUp(status) {}

void Card::Flip() {
    m_IsFaceUp != m_IsFaceUp;
}

Card::Card(const Card *other) {
    m_Suit = other->m_Suit;
    m_Rank = other->m_Rank;
    m_IsFaceUp = other->m_IsFaceUp;
}
