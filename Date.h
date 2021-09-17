//
// Created by Tr on 17.09.2021.
//

#ifndef OOP_DATE_H
#define OOP_DATE_H

#include <iostream>
#include <sstream>
#include <memory>

/*  ----1----
 *      1. Создайте класс Date с полями день, месяц, год и методами доступа к этим полям.
 *      2. Перегрузите оператор вывода для данного класса.
 *      3. Создайте два "умных" указателя today и date.
 *              Первому присвойте значение сегодняшней даты. Для него вызовите по отдельности методы доступа к полям класса Date,
 *              а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода.
 *      Затем переместите ресурс, которым владеет указатель today в указатель date.
 *      Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль.
 */

using namespace std;

class Date {
private:
    int m_year;
    int m_month;
    int m_day;
public:

    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }

    void setYear(int year) { m_year = year; }
    void setMonth(int month) { m_month = month; }
    void setDay(int day) { m_day = day; }

    friend ostream& operator<<(ostream &out, const Date &date);
    bool operator>(const Date& other) {
        if (other.getYear() > m_year) {
            return false;
        }
        else if (other.getYear() < m_year) {
            return true;
        }

        if (other.getMonth() > m_month) {
            return false;
        }
        else if (other.getMonth() < m_month) {
            return true;
        }

        if (other.getDay() > m_day) {
            return false;
        }
        else if (other.getDay() < m_day) {
            return true;
        }

        return false;
    }
    bool operator==(const Date& other) {
        if (other.getYear() == m_year) {
            if (other.getDay() == m_day) {
                if (other.getMonth() == m_month) {
                    return true;
                }
            }
        }
        return false;
    }
};

/* ---2---
 * По условию предыдущей задачи создайте два умных указателя date1 и date2.
 *          • Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и
 *              сравнивает их между собой (сравнение происходит по датам). Функция должна вернуть более позднюю дату.
 *          • Создайте функцию, которая обменивает ресурсами (датами) два умных указателя, переданных в функцию в качестве параметров.
 * Примечание: обратите внимание, что первая функция не должна уничтожать объекты, переданные ей в качестве параметров.
 */

Date CompareDates(const unique_ptr<Date>& d1, const unique_ptr<Date>& d2);
void Swap(unique_ptr<Date>& d1, unique_ptr<Date>& d2);



#endif //OOP_DATE_H
