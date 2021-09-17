#include <iostream>
#include <iomanip>
#include <assert.h>
#include <cstring>
#include <vector>
#include <map>
#include <time.h>
#include <bitset>
#include <sstream>

#include <cassert>
#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <set>

#include "Date.h"

using namespace std;
/*
 *      1. Создайте класс Date с полями день, месяц, год и методами доступа к этим полям.
 *      Перегрузите оператор вывода для данного класса.
 *      Создайте два "умных" указателя today и date.
 *          Первому присвойте значение сегодняшней даты. Для него вызовите по отдельности методы доступа к полям класса Date,
 *          а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода.
 *      Затем переместите ресурс, которым владеет указатель today в указатель date.
 *      Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль.
 */

void test_task1() {
    cout << "----------task 1----------" << endl;
    std::unique_ptr<Date> today(new Date);
    std::unique_ptr<Date> date;

    today->setYear(2021);
    today->setDay(17);
    today->setMonth(9);

    cout << "today " << *today;

    date = std::move(today);
    cout << "date " << *date;

    cout << "ptr today is " << std::boolalpha << static_cast<bool>(today) << endl;
    cout << "ptr date is " << std::boolalpha << static_cast<bool>(date) << endl;

    cout << "-------" << endl;
}

/* ---2---
 * По условию предыдущей задачи создайте два умных указателя date1 и date2.
 *          • Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и
 *              сравнивает их между собой (сравнение происходит по датам). Функция должна вернуть более позднюю дату.
 *          • Создайте функцию, которая обменивает ресурсами (датами) два умных указателя, переданных в функцию в качестве параметров.
 * Примечание: обратите внимание, что первая функция не должна уничтожать объекты, переданные ей в качестве параметров.
 */

void test_task2() {
    cout << "----------task 2----------" << endl;
    std::unique_ptr<Date> date1(new Date);
    std::unique_ptr<Date> date2(new Date);

    {   //date1 == date2
        date1->setYear(2021);
        date2->setYear(2021);

        date1->setMonth(11);
        date2->setMonth(11);

        date1->setDay(11);
        date2->setDay(11);

        Date temp = CompareDates(date1, date2);
        assert(temp == static_cast<Date>(*date1));
        assert(temp == static_cast<Date>(*date2));
        cout << temp;
        cout << "ptr date1 is " << std::boolalpha << static_cast<bool>(date1) << endl;
        cout << "ptr date2 is " << std::boolalpha << static_cast<bool>(date2) << endl;
    }
    {   //date1 < date2 by date
        date1->setYear(2021);
        date2->setYear(2021);

        date1->setMonth(11);
        date2->setMonth(11);

        date1->setDay(11);
        date2->setDay(12);

        Date temp = CompareDates(date1, date2);
        cout << temp;
        assert(temp == static_cast<Date>(*date1));
//        cout << "ptr date1 is " << std::boolalpha << static_cast<bool>(date1) << endl;
//        cout << "ptr date2 is " << std::boolalpha << static_cast<bool>(date2) << endl;
    }
    {   //date1 < date2 by month
        date1->setYear(2021);
        date2->setYear(2021);

        date1->setMonth(9);
        date2->setMonth(12);

        date1->setDay(11);
        date2->setDay(11);

        Date temp = CompareDates(date1, date2);
        cout << temp;
        assert(temp == static_cast<Date>(*date1));
//        cout << "ptr date1 is " << std::boolalpha << static_cast<bool>(date1) << endl;
//        cout << "ptr date2 is " << std::boolalpha << static_cast<bool>(date2) << endl;
    }
    {   //date1 < date2 by year
        date1->setYear(2000);
        date2->setYear(2021);

        date1->setMonth(9);
        date2->setMonth(9);

        date1->setDay(11);
        date2->setDay(11);

        Date temp = CompareDates(date1, date2);
        cout << temp;
        assert(temp == static_cast<Date>(*date1));
//        cout << "ptr date1 is " << std::boolalpha << static_cast<bool>(date1) << endl;
//        cout << "ptr date2 is " << std::boolalpha << static_cast<bool>(date2) << endl;
    }
    {   //date1 < date2 by year, day, month
        date1->setYear(2000);
        date2->setYear(2021);

        date1->setMonth(9);
        date2->setMonth(10);

        date1->setDay(11);
        date2->setDay(25);

        Date temp = CompareDates(date1, date2);
        cout << temp;
        assert(temp == static_cast<Date>(*date1));
//        cout << "ptr date1 is " << std::boolalpha << static_cast<bool>(date1) << endl;
//        cout << "ptr date2 is " << std::boolalpha << static_cast<bool>(date2) << endl;
    }
    {   //date1 > date2 by year, day, month
        date1->setYear(2022);
        date2->setYear(2021);

        date1->setMonth(9);
        date2->setMonth(10);

        date1->setDay(11);
        date2->setDay(25);

        Date temp = CompareDates(date1, date2);
        cout << temp;
        assert(temp == static_cast<Date>(*date2));
//        cout << "ptr date1 is " << std::boolalpha << static_cast<bool>(date1) << endl;
//        cout << "ptr date2 is " << std::boolalpha << static_cast<bool>(date2) << endl;
    }


    cout << "test swap" << endl;
    date1->setMonth(11);
    date1->setYear(2021);
    date1->setDay(23);

    date2->setMonth(5);
    date2->setYear(2010);
    date2->setDay(11);

    cout << "before :" << *date1 << *date2;
    Swap(date1, date2);
    cout << "after :" << *date1 << *date2;


    cout << "-------" << endl;
}

/*Создать класс Deck, который наследует от класса Hand и представляет собой колоду карт. Класс Deck имеет 4 метода:
• vold Populate() - Создает стандартную колоду из 52 карт, вызывается из конструктора.
• void Shuffle() - Метод, который тасует карты, можно использовать функцию из алгоритмов STL random_shuffle
• vold Deal (Hand& aHand) - метод, который раздает в руку одну карту
• void AddltionalCards (GenericPlayer& aGenerlcPlayer) - раздает игроку дополнительные карты до тех пор, пока он может и хочет их получать
        Обратите внимание на применение полиморфизма. В каких методах применяется этот принцип ООП?*/

void test_task3() {
    cout << "----------task 3----------" << endl;

    cout << "-------" << endl;
}

/*Реализовать класс Game, который представляет собой основной процесс игры. У этого класса будет 3 поля:
• колода карт
• рука дилера
• вектор игроков.
Конструктор класса принимает в качестве параметра вектор имен игроков и создает объекты самих игроков. В конструкторе создается колода карт и затем перемешивается.
Также класс имеет один метод play(). В этом методе раздаются каждому игроку по две стартовые карты, а первая карта дилера прячется. Далее выводится на экран информация о картах каждого игра, в т.ч. и для дилера. Затем раздаются игрокам дополнительные карты. Потом показывается первая карта дилера и дилер набирает карты, если ему надо. После этого выводится сообщение, кто победил, а кто проиграл. В конце руки всех игроков очищаются.*/

void test_task4() {
    cout << "----------task 4----------" << endl;

    cout << "-------" << endl;
}

/*Написать функцию main() к игре Блекджек. В этой функции вводятся имена игроков. Создается объект класса Game и запускается игровой процесс. Предусмотреть возможность повторной игры.*/

void test_task5() {
    cout << "----------task 5----------" << endl;

    cout << "-------" << endl;
}




int main() {
    test_task1();
    test_task2();
//    test_task3();
//    test_task4();
//    test_task5();
    std::cout << "tests passed OK" << std::endl;
    return 0;
}


