//
// Created by Tr on 12.09.2021.
//

#include "Player.h"

bool Player::IsHitting() const {
    cout << "Get one more card?, y/n" << endl;
    char ch;
    cin >> ch;

    return ch == 'y';
}

void Player::Win() const {
    cout << "Winner " << GetName() << endl;

}

void Player::Lose() const {
    cout << "Loser " << GetName() << endl;
}

void Player::Push() const {
    cout << "Draw " << GetName() << endl;
}
