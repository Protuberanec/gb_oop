#include <iostream>
#include <assert.h>
#include <vector>

#include "figures.h"
#include "Car.h"

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
Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего" базового класса создает самый "дочерний" класс.
3. Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
• математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
• унарный оператор (-)
• логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
Продемонстрировать использование перегруженных операторов.
4. Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой). Сделать поля масть и значение карты типом перечисления (enum). Положение карты - тип bool. Также в этом классе должно быть два метода:
• метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
• метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
*/




int main() {

    test_task1();
    test_task2();

    std::cout << "tests passed OK" << std::endl;
    return 0;
}
