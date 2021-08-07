#include <iostream>
#include <assert.h>

using namespace std;

#include "Power.h"
#include "RGBA.h"

/*
    1. Создать класс Power, который содержит два вещественных числа. Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел.
    Еще создать два метода: один с именем set, который позволит присваивать значения переменным, второй — calculate, который
    будет выводить результат возведения первого числа в степень второго числа. Задать значения этих двух чисел по умолчанию.
*/

void test_Power() {
    {   //test1 default constructor
        Power *test_class = new Power();
        assert(test_class->calculate() == 1);
        delete test_class;
    }
    {   //test2 constructor, and getter function
        Power *test_class = new Power(2,4);
        assert(test_class->calculate() == 16);
        assert(test_class->getBase() == 2);
        assert(test_class->getPower() == 4);
        delete test_class;
    }

    {   //test3 setter power
        Power *test_class = new Power(2,4);
        test_class->setPower(5);
        assert(test_class->calculate() == 32);
        delete test_class;
    }

    {   //test4 setter base
        Power *test_class = new Power(2,4);
        test_class->setBase(5);
        assert(test_class->calculate() == 625);
        delete test_class;
    }

    cout << "test class Power is OK" << endl;
}

/*
    2. Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t:
    m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу).
    Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha.
    Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения
    для m_red, m_blue, m_green и m_alpha. Написать функцию print(), которая будет выводить значения переменных-членов.
*/
void test_RGBA() {
    {   //test 1 default constructor
        RGBA *test_rgba = new RGBA();
        test_rgba->print();
        delete [] test_rgba;
    }
    {   //test 2 constructor
        RGBA *test_rgba = new RGBA(14,20,34,90);
        test_rgba->print();
        delete [] test_rgba;
    }
}
/*    3. Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
        ◦ private-массив   целых чисел длиной 10;
        ◦ private целочисленное значение для отслеживания длины стека;
        ◦ public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
        ◦ public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
        ◦ public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться   предупреждение;
        ◦ public-метод с именем print(), который будет выводить все значения стека.
*/


int main() {

    test_Power();
    test_RGBA();


    std::cout << "tests passed OK" << std::endl;
    return 0;
}
