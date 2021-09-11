//
// Created by Tr on 11.09.2021.
//

#include "GenericPlayer.h"

void GenericPlayer::Bust() {
    std::cout << name << std::endl;

    std::cout << (IsBoosted() == true ? "excess" : "no excess") << std::endl;
}

bool GenericPlayer::IsBoosted() {
    return getValue() > 21;
}
