//
// Created by Tr on 12.09.2021.
//

#include "House.h"

bool House::IsHitting() const {
    if (getValue() > 16) {
        return false;
    }
    return true;
}

void House::FlipFirstCard() {
    FlipCard(0);
}
