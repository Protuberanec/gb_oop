//
// Created by Tr on 10.09.2021.
//

#ifndef OOP_MYPAIR_H
#define OOP_MYPAIR_H

template<class T>
class myPair {
private:
    T m_first;
    T m_second;
public:
    T first() const {
        return m_first;
    }

    T second() const {
        return m_second;
    }
};


#endif //OOP_MYPAIR_H
