#include <iostream>
#include <assert.h>
#include <vector>

#include "figures.h"
#include "Car.h"
#include "fraction.h"

using namespace std;
/*
 * 1. Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг).
 * Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб).
 * Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь).
 * Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
 */
void test_task1() {
    cout << "----------task 1----------" << endl;
    Parallelogram *parallelogram1 = new Parallelogram(10.0, 50.0, 35.0);
    cout << parallelogram1->area() << endl;

    Circle *circle1 = new Circle(10);
    cout << circle1->area() << endl;

    Square *square1 = new Square(11);
    cout << square1->area() << endl;

    Rhombus *rhombus1 = new Rhombus(10,10);
    cout << rhombus1->area() << endl;
    cout << "-------" << endl;
}

 /*
  * 2. Создать класс Car (автомобиль) с полями company (компания) и model (модель).
  * Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус).
  * От этих классов наследует класс Minivan (минивэн).
  * Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.
  * Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы.
  * Обратить внимание на проблему «алмаз смерти».
  * Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего" базового класса создает самый "дочерний" класс.
  */
void test_task2() {
    cout << "----------task 2----------" << endl;
    cout << "\t\tcreate car" << endl;
    Car* car1 = new Car();
    cout << "\t\tcreate bus" << endl;
    Bus* bus1 = new Bus();
    cout << "\t\tcreate passenger car" << endl;
    PassengerCar* passengerCar1 = new PassengerCar();
    cout << "\t\tcreate minivan" << endl;
    Minivan* minivan = new Minivan();
    cout << "-------" << endl;
}

/*
 * 3. Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2).
 * Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
 *  • математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
 *  • унарный оператор (-)
 *  • логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
 *  Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
 *  Продемонстрировать использование перегруженных операторов.
 */
void showFractions(const Fraction& _fr0, const Fraction& _fr1, const char* _operator) {
    _fr0.print();
    cout <<  _operator << " ";
    _fr1.print();
}
void test_task3() {
    cout << "----------task 3----------" << endl;
    {   //check sum with similar denominator
        Fraction *fractionNumber = new Fraction(3, 11);

        *fractionNumber = *fractionNumber + Fraction(2, 11);
        assert(fractionNumber->getDenominator() == 11);
        assert(fractionNumber->getNumerator() == 5);
        fractionNumber->print();
        delete fractionNumber;
    }

    {   //check sum with different denominator
        Fraction *fractionNumber = new Fraction(3, 5);

        *fractionNumber = *fractionNumber + Fraction(2, 11);
        assert(fractionNumber->getDenominator() == 55);
        assert(fractionNumber->getNumerator() == 43);
        fractionNumber->print();
        delete fractionNumber;
    }

    {   //check minus with similar denominator
        Fraction *fractionNumber = new Fraction(3, 11);

        *fractionNumber = *fractionNumber - Fraction(2, 11);
        assert(fractionNumber->getDenominator() == 11);
        assert(fractionNumber->getNumerator() == 1);
        fractionNumber->print();
        delete fractionNumber;
    }

    {   //check minus with different denominator
        Fraction *fractionNumber = new Fraction(3, 5);

        *fractionNumber = *fractionNumber - Fraction(2, 11);
        assert(fractionNumber->getDenominator() == 55);
        assert(fractionNumber->getNumerator() == 23);
        fractionNumber->print();
        delete fractionNumber;
    }

    {   //check minus with similar denominator
        Fraction *fractionNumber = new Fraction(1, 16);

        *fractionNumber = *fractionNumber - Fraction(2, 16);
        assert(fractionNumber->getDenominator() == 16);
        assert(fractionNumber->getNumerator() == -1);
        fractionNumber->print();
        delete fractionNumber;
    }

    {   //check multiply
        Fraction *fractionNumber = new Fraction(5, 11);

        *fractionNumber = *fractionNumber * Fraction(15, 11);
        assert(fractionNumber->getDenominator() == 121);
        assert(fractionNumber->getNumerator() == 75);
        fractionNumber->print();
    }

    {   //check division
        Fraction *fractionNumber = new Fraction(5, 11);

        *fractionNumber = *fractionNumber / Fraction(15, 11);
        assert(fractionNumber->getDenominator() == 165);
        assert(fractionNumber->getNumerator() == 55);
        fractionNumber->print();
        delete fractionNumber;
    }

    {   //check minus unarny operator
        Fraction *fractionNumber = new Fraction(5, 11);
        Fraction testFr = -*fractionNumber;
        fractionNumber->print();
        testFr.print();

        *fractionNumber = -*fractionNumber; //я так понимаю при такой реализации будет утечка памяти... как сделать, чтобы её не было?
        fractionNumber->print();
        delete fractionNumber;
    }

    cout << "\n\t\tcheck ==" << endl;
    {   //check ==
        Fraction *fractionNumber0 = new Fraction(5, 11);
        Fraction *fractionNumber1 = new Fraction(5, 11);

        showFractions(*fractionNumber0, *fractionNumber1, "==");
        cout << (*fractionNumber0 == *fractionNumber1 ? "is true" : "is false") << endl;

        delete fractionNumber0;
        delete fractionNumber1;
    }
    {   //check ==
        Fraction *fractionNumber0 = new Fraction(5, 12);
        Fraction *fractionNumber1 = new Fraction(5, 11);
        showFractions(*fractionNumber0, *fractionNumber1, "==");
        cout << (*fractionNumber0 == *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber0;
        delete fractionNumber1;
    }
    {   //check ==
        Fraction *fractionNumber0 = new Fraction(7, 11);
        Fraction *fractionNumber1 = new Fraction(5, 11);

        showFractions(*fractionNumber0, *fractionNumber1, "==");
        cout << (*fractionNumber0 == *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber0;
        delete fractionNumber1;
    }
    {   //check ==
        Fraction *fractionNumber0 = new Fraction(7, 11);
        Fraction *fractionNumber1 = new Fraction(5, 12);

        showFractions(*fractionNumber0, *fractionNumber1, "==");
        cout << (*fractionNumber0 == *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber0;
        delete fractionNumber1;
    }
    {   //check ==
        Fraction *fractionNumber0 = new Fraction(1, 5);
        Fraction *fractionNumber1 = new Fraction(2, 10);

        assert((*fractionNumber0 == *fractionNumber1) == true);
        showFractions(*fractionNumber0, *fractionNumber1, "==");
        cout << (*fractionNumber0 == *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }

    cout << "\t\tcheck !=" << endl;
    {   //check !=
        Fraction *fractionNumber0 = new Fraction(5, 11);
        Fraction *fractionNumber1 = new Fraction(5, 11);

        showFractions(*fractionNumber0, *fractionNumber1, "!=");
        cout << (*fractionNumber0 != *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }
    {   //check !=
        Fraction *fractionNumber0 = new Fraction(5, 12);
        Fraction *fractionNumber1 = new Fraction(5, 11);

        showFractions(*fractionNumber0, *fractionNumber1, "!=");
        cout << (*fractionNumber0 != *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }
    {   //check !=
        Fraction *fractionNumber0 = new Fraction(7, 11);
        Fraction *fractionNumber1 = new Fraction(5, 11);

        showFractions(*fractionNumber0, *fractionNumber1, "!=");
        cout << (*fractionNumber0 != *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }
    {   //check !=
        Fraction *fractionNumber0 = new Fraction(7, 11);
        Fraction *fractionNumber1 = new Fraction(5, 12);

        showFractions(*fractionNumber0, *fractionNumber1, "!=");
        cout << (*fractionNumber0 != *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }

    cout << "\t\tcheck <" << endl;
    {   //check <
        Fraction *fractionNumber0 = new Fraction(7, 11);
        Fraction *fractionNumber1 = new Fraction(5, 11);
        assert((*fractionNumber0 < *fractionNumber1) == false);

        showFractions(*fractionNumber0, *fractionNumber1, "<");
        cout << (*fractionNumber0 < *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }
    {   //check <
        Fraction *fractionNumber0 = new Fraction(7, 11);
        Fraction *fractionNumber1 = new Fraction(9, 11);

        assert((*fractionNumber0 < *fractionNumber1) == true);
        showFractions(*fractionNumber0, *fractionNumber1, "<");
        cout << (*fractionNumber0 < *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }
    {   //check <
        Fraction *fractionNumber0 = new Fraction(7, 5);
        Fraction *fractionNumber1 = new Fraction(9, 11);

        assert((*fractionNumber0 < *fractionNumber1) == false);
        showFractions(*fractionNumber0, *fractionNumber1, "<");
        cout << (*fractionNumber0 < *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }

    cout << "\t\tcheck >" << endl;
    {   //check <
        Fraction *fractionNumber0 = new Fraction(7, 11);
        Fraction *fractionNumber1 = new Fraction(5, 11);

        assert((*fractionNumber0 > *fractionNumber1) == true);

        showFractions(*fractionNumber0, *fractionNumber1, ">");
        cout << (*fractionNumber0 > *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }
    {   //check <
        Fraction *fractionNumber0 = new Fraction(7, 11);
        Fraction *fractionNumber1 = new Fraction(9, 11);

        assert((*fractionNumber0 > *fractionNumber1) == false);
        showFractions(*fractionNumber0, *fractionNumber1, ">");
        cout << (*fractionNumber0 > *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }
    {   //check <
        Fraction *fractionNumber0 = new Fraction(7, 5);
        Fraction *fractionNumber1 = new Fraction(9, 11);

        assert((*fractionNumber0 > *fractionNumber1) == true);
        showFractions(*fractionNumber0, *fractionNumber1, ">");
        cout << (*fractionNumber0 > *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }

    cout << "\t\tcheck >=" << endl;
    {   //check >=
        Fraction *fractionNumber0 = new Fraction(7, 11);
        Fraction *fractionNumber1 = new Fraction(5, 11);

        assert((*fractionNumber0 >= *fractionNumber1) == true);

        showFractions(*fractionNumber0, *fractionNumber1, ">=");
        cout << (*fractionNumber0 >= *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }
    {   //check >=
        Fraction *fractionNumber0 = new Fraction(7, 11);
        Fraction *fractionNumber1 = new Fraction(9, 11);

        assert((*fractionNumber0 >= *fractionNumber1) == false);
        showFractions(*fractionNumber0, *fractionNumber1, ">=");
        cout << (*fractionNumber0 >= *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }
    {   //check >=
        Fraction *fractionNumber0 = new Fraction(7, 5);
        Fraction *fractionNumber1 = new Fraction(9, 11);

        assert((*fractionNumber0 >= *fractionNumber1) == true);
        showFractions(*fractionNumber0, *fractionNumber1, ">=");
        cout << (*fractionNumber0 >= *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }
    {   //check >=
        Fraction *fractionNumber0 = new Fraction(7, 11);
        Fraction *fractionNumber1 = new Fraction(7, 11);

        assert((*fractionNumber0 >= *fractionNumber1) == true);
        showFractions(*fractionNumber0, *fractionNumber1, ">=");
        cout << (*fractionNumber0 >= *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }
    {   //check >=
        Fraction *fractionNumber0 = new Fraction(1, 5);
        Fraction *fractionNumber1 = new Fraction(2, 10);

        assert((*fractionNumber0 >= *fractionNumber1) == true);
        showFractions(*fractionNumber0, *fractionNumber1, ">=");
        cout << (*fractionNumber0 >= *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }

    cout << "\t\tcheck <=" << endl;
    {   //check <=
        Fraction *fractionNumber0 = new Fraction(7, 11);
        Fraction *fractionNumber1 = new Fraction(5, 11);

        assert((*fractionNumber0 <= *fractionNumber1) == false);

        showFractions(*fractionNumber0, *fractionNumber1, "<=");
        cout << (*fractionNumber0 <= *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }
    {   //check <=
        Fraction *fractionNumber0 = new Fraction(7, 11);
        Fraction *fractionNumber1 = new Fraction(9, 11);

        assert((*fractionNumber0 <= *fractionNumber1) == true);
        showFractions(*fractionNumber0, *fractionNumber1, "<=");
        cout << (*fractionNumber0 <= *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }
    {   //check <=
        Fraction *fractionNumber0 = new Fraction(7, 5);
        Fraction *fractionNumber1 = new Fraction(9, 11);

        assert((*fractionNumber0 <= *fractionNumber1) == false);
        showFractions(*fractionNumber0, *fractionNumber1, "<=");
        cout << (*fractionNumber0 <= *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }
    {   //check <=
        Fraction *fractionNumber0 = new Fraction(7, 11);
        Fraction *fractionNumber1 = new Fraction(7, 11);

        assert((*fractionNumber0 <= *fractionNumber1) == true);
        showFractions(*fractionNumber0, *fractionNumber1, "<=");
        cout << (*fractionNumber0 <= *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }
    {   //check <=
        Fraction *fractionNumber0 = new Fraction(1, 5);
        Fraction *fractionNumber1 = new Fraction(2, 10);

        assert((*fractionNumber0 <= *fractionNumber1) == true);
        showFractions(*fractionNumber0, *fractionNumber1, "<=");
        cout << (*fractionNumber0 <= *fractionNumber1 ? "is true" : "is false") << endl;
        delete fractionNumber1;
        delete fractionNumber0;
    }

    cout << "-------" << endl;
}

 /*
  * 4. Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три поля:
  * масть, значение карты и положение карты (вверх лицом или рубашкой).
  * Сделать поля масть и значение карты типом перечисления (enum). Положение карты - тип bool.
  * Также в этом классе должно быть два метода:
  *         • метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх,
  *           то он ее поворачивает лицом вверх, и наоборот.
  *         • метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
*/

 void test_task4() {

    //class of card is placed in Card.*
 }

int main() {

    test_task1();
    test_task2();
    test_task3();
    test_task4();

    std::cout << "tests passed OK" << std::endl;
    return 0;
}
