//
// Created by Tr on 07.08.2021.
//

#include "RGBA.h"

RGBA::RGBA() {

    m_red = 10;
    m_green = 100;
    m_blue = 200;
    m_alpha = 125;

    uint8_t *pColor = &m_red;
    for (int i = 0; i < 4; i++) {
        *pColor++ = 0x00;
    }
}

RGBA::RGBA(uint8_t mRed, uint8_t mGreen, uint8_t mBlue, uint8_t mAlpha) : m_red(mRed), m_green(mGreen), m_blue(mBlue),
                                                                          m_alpha(mAlpha) {}

void RGBA::print() const {
    cout << "\nred\t: " << static_cast<int>(m_red);
    cout << "\ngreen\t: " << static_cast<int>(m_green);
    cout << "\nblue\t: " << static_cast<int>(m_blue);
    cout << "\nalpha\t: " << static_cast<int>(m_alpha);
    cout << endl;
}
