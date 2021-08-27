//
// Created by Tr on 27.08.2021.
//

#include "STUDENT.h"


unsigned int STUDENT::amountStudents = 0;


STUDENT::STUDENT() : PERSON() {
    ++amountStudents;
    studyYear = 0;
}
STUDENT::~STUDENT() {
    --amountStudents;

    cout << "student " << getName() << " is hired" << endl;
}

STUDENT::STUDENT(const string& name, bool gender,  unsigned short age) : PERSON(name, gender, age){
    ++amountStudents;
    studyYear = 0;
}

void STUDENT::upStudyYear(int setYear) {
    if (setYear == 0) {
        studyYear++;
    }
    else {
        studyYear = setYear;
    }
}

int STUDENT::getAmountStudents() const {
    return amountStudents;
}

void STUDENT::printInfo() const {
    string infoStud;
    infoStud.append("name: ");
    infoStud.append(getName());
    infoStud.append("\tage: ");
    infoStud.append(to_string(getAge()));
    infoStud.append("\tyear of study: ");
    infoStud.append(to_string(studyYear));
    infoStud.append("\tgender: ");
    infoStud.append(Gender());

    cout << infoStud << endl;
}
