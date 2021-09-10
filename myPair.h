//
// Created by Tr on 10.09.2021.
//

#ifndef OOP_MYPAIR_H
#define OOP_MYPAIR_H

#include <string>

using namespace std;

/*
 * 1. Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами.
 */
template<class T>
class myPair {
private:
    T m_first;
    T m_second;
public:
    myPair(T mFirst, T mSecond) : m_first(mFirst), m_second(mSecond) {}

    T first() const {
        return m_first;
    }

    T second() const {
        return m_second;
    }
};

/*
 * 2. Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.
 */

template<class T, class P>
class myPairM {
public:
    T m_first;
    P m_second;
public:
    myPairM() {}
    myPairM(T mFirst, P mSecond) : m_first(mFirst), m_second(mSecond) {}

    T first() const {
        return m_first;
    }

    P second() const {
        return m_second;
    }
};

/*
 *  3. Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, \
 *  а второе — любого типа. Этот шаблон класса должен наследовать частично специализированный класс Pair,
 *  в котором первый параметр — string, а второй — любого типа данных.
 */

template<class P>
class myPairM <std::string&, P> {
public:
    std::string m_first;
    P m_second;
public:
    myPairM() {}
    myPairM(const std::string& mFirst, P mSecond) : m_first(mFirst), m_second(mSecond) {}

    std::string first() const {
        return m_first;
    }

    P second() const {
        return m_second;
    }
};

template<class T>
class StringValuePair : public myPairM<std::string&, T> {
public:
    StringValuePair() {}
    StringValuePair(const std::string& str, T val) : myPairM<std::string &, T>(str, val){}

};


#endif //OOP_MYPAIR_H
