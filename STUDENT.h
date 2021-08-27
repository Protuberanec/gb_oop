//
// Created by Tr on 27.08.2021.
//

#ifndef OOP_STUDENT_H
#define OOP_STUDENT_H

#include <iostream>
#include "PERSON.h"

using namespace std;


/*
 * 1. Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить методы переназначения имени, изменения возраста и веса.
 * Создать производный класс Student (студент), имеющий поле года обучения. Определить методы переназначения и увеличения этого значения.
 * Создать счетчик количества созданных студентов. В функции main() создать несколько студентов. По запросу вывести определенного человека.
 */

using Student = class STUDENT;


class STUDENT : public PERSON {
private:
    static unsigned int amountStudents;
    unsigned int studyYear;
public:
    STUDENT();
    STUDENT(const string& name, bool gender, unsigned short age);
    ~STUDENT();
    void upStudyYear(int setYear = 0);
    int getAmountStudents() const;

    void printInfo() const;
};



#endif //OOP_STUDENT_H
