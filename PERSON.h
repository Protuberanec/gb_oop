//
// Created by Tr on 27.08.2021.
//

#ifndef OOP_PERSON_H
#define OOP_PERSON_H
#include <string>
using namespace std;

enum GENDER {
    WOMAN = 0,
    MAN = 1,
};

class PERSON {
private:
    unsigned short age; //mo more than 2^16
    unsigned short weight;  //mo more than 2^16
    bool gender;
    //assume only two possible gender MAN and WOMAN
    string name;
public:

    PERSON();
    PERSON(const string& name, bool gender, unsigned short age);

    const string &getName() const;
    void setName(const string &name);

    unsigned short getWeight() const;
    void setWeight(unsigned short weight);

    unsigned short getAge() const;
    void setAge(unsigned short age);

    string Gender() const;
};




#endif //OOP_PERSON_H
