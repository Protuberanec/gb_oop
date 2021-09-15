//
// Created by Tr on 11.09.2021.
//

#include "GenericPlayer.h"

void GenericPlayer::Bust() const {
    std::cout << m_Name << std::endl;

    std::cout << (IsBoosted() == true ? "excess" : "no excess") << std::endl;
}

bool GenericPlayer::IsBoosted() const {
    return getValue() > 21;
}

GenericPlayer::~GenericPlayer() {

}
