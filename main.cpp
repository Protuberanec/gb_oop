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

#include "myPair.h"

using namespace std;

/*
 *  1. Создать программу, которая считывает целое число типа int. И поставить «защиту от дурака»: если пользователь
 *  вводит что-то кроме одного целочисленного значения, нужно вывести сообщение об ошибке и предложить ввести число еще раз.
 *  Пример неправильных введенных строк:
 */

pair<bool, int> GetNumber(bool infiniteWaitNumber = false, istream& input = cin) {
    int number;
    cout << "I wait a number : ";

    string strInput;
    getline(input, strInput);

    while(1) {
        int i = 0;
        while (strInput[i] >= 0x30 && strInput[i] <= 0x39) {
            i++;
        }
        if (i < strInput.size()) {
            cout << "\nplease try again, I wait a number : ";
            if (infiniteWaitNumber == false) {
                cout << endl;
                //can be used as recursive function to call again GetNumber(...)
                return {false, 0};
            }
            strInput.clear();
            getline(input, strInput);
        }
        else {
            break;
        }
    }

    cout << endl;
    return {true, number};
}

void test_task1() {
    cout << "----------task 1----------" << endl;
    {   //test is not number
        stringstream tempInputCin;
        tempInputCin.str("fdasf4241");
        auto res = GetNumber(false, tempInputCin);
        assert(res.first == false);
    }
    {   //test is not number
        stringstream tempInputCin;
        tempInputCin.str("14324nffa");
        auto res = GetNumber(false, tempInputCin);
        assert(res.first == false);
    }
    {   //test is not number
        stringstream tempInputCin;
        tempInputCin.str("sdaf.432fs143fdsf24nffa432");
        auto res = GetNumber(false, tempInputCin);
        assert(res.first == false);
    }
    {//test is number
        stringstream tempInputCin;
        tempInputCin.str("14324");
        auto res = GetNumber(false, tempInputCin);
        assert(res.first == true);
    }
    cout << "\t---infinite test---" << endl;
    GetNumber(true);    //infinite enter number
    cout << "-------" << endl;
}

/*
 * 2. Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает буфер.
 */

struct toggled_ostream
{
    std::ostream& os;
};


class toggle_t {};
constexpr toggle_t endll;

inline toggled_ostream operator << (std::ostream& os, toggle_t)
{
    os << endl << endl;
    return { os };
}

template <typename T>
std::ostream& operator << (toggled_ostream tos, const T& v)
{
    return tos.os << v;
}

void test_task2() {
    cout << "----------task 2----------" << endl;
    cout << "after it will used double next string" << endll;
    cout << "test1" << endl;
    cout << "-------" << endl;
}

/*
 *  3. Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4 метода:
 *              • virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса.
 *                  Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
 *              • void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
 *              • void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
 *              • void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.
 */

void test_task3() {
    cout << "----------task 3----------" << endl;


    cout << "-------" << endl;
}
/*
 *     4. Реализовать класс House, который представляет дилера. Этот класс наследует от класса GenericPlayer. У него есть 2 метода:
 *          • virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. Если у дилера не больше 16 очков, то он берет еще одну карту.
 *          • void FlipFirstCard() - метод переворачивает первую карту дилера.
 */
void test_task4() {
    cout << "----------task 4----------" << endl;


    cout << "-------" << endl;
}
/*
 * Написать перегрузку оператора вывода для класса Card. Если карта перевернута рубашкой вверх (мы ее не видим),
 * вывести ХХ, если мы ее видим, вывести масть и номинал карты. Также для класса GenericPlayer написать перегрузку оператора вывода,
 * который должен отображать имя игрока и его карты, а также общую сумму очков его карт.
 */
void test_task5() {
    cout << "----------task 5----------" << endl;


    cout << "-------" << endl;
}

struct Date {
    int year;
    int month;
    int day;

    Date(int year, int month, int day) : year(year), month(month), day(day) {}
};

ostream& operator<< (ostream &out, const Date &date)
{
    out << "Date: " << date.day << ". " << date.month << ". " << date.year << "\n";
    return out;
}

istream& operator>> (istream &in, Date &date)
{
    // обратите внимание, параметр date (объект класса Date) должен быть не константным, чтобы мы имели возможность изменить члены класса
    in >> date.day;
    in >> date.month;
    in >> date.year;

    return in;
}



int main() {
    test_task1();
    test_task2();
    test_task3();
    test_task4();
    test_task5();
    std::cout << "tests passed OK" << std::endl;
    return 0;
}




//Date temp(2021,12,14);
//
//cin >> temp;
//
//cout << temp << endl;
//
//
//return 0;
