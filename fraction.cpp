//
// Created by Tr on 30.08.2021.
//

#include "fraction.h"

int Fraction::getNumerator() const {
    return numerator;
}

void Fraction::setNumerator(int numerator) {
    Fraction::numerator = numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setDenominator(int denominator) {
    if (denominator == 0) {
        //what's need to do??
        assert(denominator == 0);
    }

    Fraction::denominator = denominator;
}

void Fraction::print() const {
    cout << numerator << "/" << denominator << " ";
}

Fraction::Fraction(int _numerator, int _denominator) : numerator(_numerator), denominator(_denominator) {
    assert(_denominator);
}

Fraction& Fraction::operator+(const Fraction& fr) {
    if (denominator == 0 || fr.denominator == 0) {
        return *this;
    }

    if (fr.denominator == this->denominator) {
        this->numerator += fr.numerator;
    }
    else {
        //very simple method... without NOD...
        this->numerator = this->numerator*fr.denominator + fr.numerator*this->denominator;
        this->denominator = this->denominator * fr.denominator;
    }
    return *this;
}

Fraction &Fraction::operator-(const Fraction &fr) {
    if (denominator == 0 || fr.denominator == 0) {
        return *this;
    }

    if (fr.denominator == this->denominator) {
        this->numerator -= fr.numerator;
    }
    else {
        //very simple method... without NOD...
        this->numerator = this->numerator*fr.denominator - fr.numerator*this->denominator;
        this->denominator = this->denominator * fr.denominator;
    }
    return *this;
}

Fraction &Fraction::operator*(const Fraction &fr) {
    if (denominator == 0 || fr.denominator == 0) {
        return *this;
    }

    this->numerator = this->numerator*fr.numerator;
    this->denominator = this->denominator * fr.denominator;

    return *this;
}

Fraction &Fraction::operator/(const Fraction &fr) {
    if (denominator == 0 || fr.denominator == 0) {
        return *this;
    }

    int tempNumerator = this->numerator*fr.denominator;
    this->denominator = this->denominator * fr.numerator;
    this->numerator = tempNumerator;

    return *this;
}

Fraction &Fraction::operator-() const {
    return *new Fraction(-numerator, denominator);
}

bool operator==(const Fraction &fr0, const Fraction &fr1) {
    assert(fr0.getDenominator());
    assert(fr1.getDenominator());
    int tempNumerator0 = fr0.getNumerator() * fr1.getDenominator();
    int tempNumerator1 = fr1.getNumerator() * fr0.getDenominator();
    return  tempNumerator0 == tempNumerator1;
}
bool operator!=(const Fraction &fr, const Fraction &fr1) {
    return !(fr == fr1);
}
bool operator>(const Fraction &fr0, const Fraction &fr1) {
    assert(fr0.getDenominator());
    assert(fr1.getDenominator());

    int tempNumerator0 = fr0.getNumerator() * fr1.getDenominator();
    int tempNumerator1 = fr1.getNumerator() * fr0.getDenominator();
    return  tempNumerator0 > tempNumerator1;
}

bool operator<(const Fraction &fr, const Fraction &fr1) {
    return !(fr > fr1);
}

bool operator>=(const Fraction &fr0, const Fraction &fr1) {
    assert(fr0.getDenominator());
    assert(fr1.getDenominator());

    int tempNumerator0 = fr0.getNumerator() * fr1.getDenominator();
    int tempNumerator1 = fr1.getNumerator() * fr0.getDenominator();
    return  tempNumerator0 >= tempNumerator1;
}
bool operator<=(const Fraction &fr0, const Fraction &fr1) {
    if (fr0 == fr1)
        return true;

    return !(fr0 > fr1);
}