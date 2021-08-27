#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;
/*
 * 1. Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить методы переназначения имени, изменения возраста и веса.
 * Создать производный класс Student (студент), имеющий поле года обучения. Определить методы переназначения и увеличения этого значения.
 * Создать счетчик количества созданных студентов. В функции main() создать несколько студентов. По запросу вывести определенного человека.
 */
#include "STUDENT.h"
void TestPersonClass() {
    cout << "task1: class Person, and Student inherited from person" << endl;
    vector<Student*> groupStudents;
    Student *stud = new Student("Igor", GENDER::MAN, 18);
    groupStudents.push_back(stud);
    stud = new Student("Polina", GENDER::WOMAN, 17);
    groupStudents.push_back(stud);

    stud = new Student();
    groupStudents.push_back(stud);

    groupStudents[0]->printInfo();
    groupStudents[1]->printInfo();
    groupStudents[2]->printInfo();

    //release memory!!! eco action!!!
    for (auto& stud : groupStudents) {
        delete stud;
    }
    groupStudents.clear();
}

/*
 * 2. Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
 * У Fruit есть две переменные-члена: name (имя) и color (цвет).
 * Добавить новый класс GrannySmith, который наследует класс Apple.
 int main()
    {
        Apple a("red");
        Banana b;
        GrannySmith c;

        std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
        std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
        std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

        return 0;
    }

    Код, приведенный выше, должен давать следующий результат:

    My apple is red.
    My banana is yellow.
    My Granny Smith apple is green.
*/

//3. Изучить правила игры в Blackjack. Подумать, как написать данную игру на С++, используя объектно-ориентированное программирование.
// Сколько будет классов в программе? Какие классы будут базовыми, а какие производными?
// Продумать реализацию игры с помощью классов и записать результаты.

int main() {
    TestPersonClass();

    std::cout << "tests passed OK" << std::endl;
    return 0;
}
