#include <iostream>
#include <assert.h>
#include <vector>
#include <map>
#include <time.h>

#include "ArrayInt.h"

using namespace std;
/*
 * 1. Добавить в контейнерный класс, который был написан в этом уроке, методы:
 *      • для удаления последнего элемента массива (аналог функции pop_back() в векторах)
 *      • для удаления первого элемента массива (аналог pop_front() в векторах)
 *      • для сортировки массива
 *      • для вывода на экран элементов.
 */
void test_task1() {
    cout << "----------task 1----------" << endl;
    {   //test remove last element
        cout << "test remove last element" << endl;
        ArrayInt *tempArray = new ArrayInt;
        const int AM_EL = 5;
        for (int i = 0; i < AM_EL; i++) {
            tempArray->push_back(i);
        }
        tempArray->showElements();
        for (int i = 0; i < AM_EL/**/; i++) {
            tempArray->removeLast();
            tempArray->showElements();
        }

    }
    {   //test remove first element
        cout << "test remove first element" << endl;
        ArrayInt *tempArray = new ArrayInt;
        const int AM_EL = 5;
        for (int i = 0; i < AM_EL; i++) {
            tempArray->push_back(i);
        }
        tempArray->showElements();
        for (int i = 0; i < AM_EL/**/; i++) {
            tempArray->removeFirst();
            tempArray->showElements();
        }
    }
    {   //sort up, and down
        cout << "test remove first element" << endl;
        ArrayInt *tempArray = new ArrayInt;
        const int AM_EL = 20;
        srand(time(NULL));
        for (int i = 0; i < AM_EL; i++) {
            tempArray->push_back(rand() % 100);
        }
        tempArray->showElements();

        tempArray->sortDown();
        cout << "sort down : ";
        tempArray->showElements();
        tempArray->sortUp();
        cout << "sort up : ";
        tempArray->showElements();
    }

    cout << "-------" << endl;
}

/*
 * 2. Дан вектор чисел, требуется выяснить, сколько среди них различных. Постараться использовать максимально быстрый алгоритм.
 */

void test_task2() {
    cout << "----------task 2----------" << endl;
    vector<int> tempVect = {4,48,6,2,6,5,5,6,0,1,3,9,9,8,2,27,8,2,3,5,8,888,23,45,92,4,0,0,0,5,89};
    map<int,int> uniqueNum;
    //не знаю насколько это хорошо....
    for (int el : tempVect) {
        uniqueNum[el]++;
    }
    cout << "unique num : ";
    for (auto element : uniqueNum) {
        if (element.second == 1) {
            cout << element.first << " ";
        }
    }
    cout << endl;
//вывод с помощью итераторов
    cout << "again show with usage of iterator ";
    for (map<int,int>::iterator el = uniqueNum.begin(); el != uniqueNum.end(); el++) {
        if (el->second == 1) {
            cout << el->first << " ";
        }
    }

    cout << endl;
    cout << "-------" << endl;
}


/*
 * 3. Реализовать класс Hand, который представляет собой коллекцию карт.
 * В классе будет одно поле: вектор указателей карт (удобно использовать вектор, т.к. это по сути динамический массив,
 * а тип его элементов должен быть - указатель на объекты класса Card). Также в классе Hand должно быть 3 метода:
 *      • метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
 *      • метод Clear, который очищает руку от карт
 *      • метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11).
*/


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
