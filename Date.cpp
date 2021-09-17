//
// Created by Tr on 17.09.2021.
//

#include "Date.h"

ostream& operator<< (ostream &out, const Date &date)
{
    out << "Date: " << date.m_day << "." << date.m_month << "." << date.m_year << "\n";
    return out;
}

Date CompareDates(const unique_ptr<Date>& d1, const unique_ptr<Date>& d2) {
    if (*d1 > *d2) {
        return static_cast<Date>(*d2);
    }
    return static_cast<Date>(*d1);
}

void Swap(unique_ptr<Date>& d1, unique_ptr<Date>& d2) {
    unique_ptr<Date> temp = move(d1);
    d1 = move(d2);
    d2 = move(temp);

}
