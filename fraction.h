//
// Created by Tr on 30.08.2021.
//

#ifndef OOP_FRACTION_H
#define OOP_FRACTION_H

#include <assert.h>
#include "iostream"

using namespace std;
/*
 * 3. Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2).
 * Предусмотреть, чтобы знаменатель не был равен 0.
 * Перегрузить:
 *        • математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
 *        • унарный оператор (-)
 *        • логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
 *  Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
 *  Продемонстрировать использование перегруженных операторов.
 */

class Fraction {
private:
    int numerator;    //分子 благодарен этим курсам теперь я знаю как это будет по-английски... и заодно по-китайски...
    int denominator;  //分母
public:
    Fraction();
    Fraction(int _numerator, int _denominator);

    int getNumerator() const;
    void setNumerator(int numerator);
    int getDenominator() const;
    void setDenominator(int denominator);
    void print() const;

    Fraction& operator+(const Fraction& fr);
    Fraction& operator-(const Fraction& fr);
    Fraction& operator*(const Fraction& fr);
    Fraction& operator/(const Fraction& fr);
    Fraction& operator-() const;
};

bool operator==(const Fraction &fr, const Fraction &fr1);
bool operator!=(const Fraction &fr, const Fraction &fr1);
bool operator>(const Fraction &fr, const Fraction &fr1);
bool operator<(const Fraction &fr, const Fraction &fr1);
bool operator>=(const Fraction &fr, const Fraction &fr1);
bool operator<=(const Fraction &fr, const Fraction &fr1);


#endif //OOP_FRACTION_H


