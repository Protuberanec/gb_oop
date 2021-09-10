#include <iostream>
#include <assert.h>
#include <vector>
#include <map>
#include <time.h>

#include "myPair.h"

using namespace std;
/*
 * 1. Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами.
 */
void test_task1() {
    cout << "----------task 1----------" << endl;
    myPair<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const myPair<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    cout << "-------" << endl;
}

/*
 * 2. Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.
 */
void test_task2() {
    cout << "----------task 2----------" << endl;
    myPairM<int, double> p1(6, 7.8);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const myPairM<double, int> p2(3.4, 5);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    myPairM<std::string&, int> p3("test", 4);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';


    StringValuePair<int> svp("Amazing", 7);
    cout << "svp Pair: " << svp.first() << ' ' << svp.second() << '\n';



    cout << "-------" << endl;
}





void test_task3() {
    cout << "----------task 3----------" << endl;


    cout << "-------" << endl;
}

int main() {
    test_task1();
    test_task2();
    test_task3();
    std::cout << "tests passed OK" << std::endl;
    return 0;
}
