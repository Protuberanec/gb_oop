//
// Created by Tr on 07.09.2021.
//

#ifndef OOP_ARRAYINT_H
#define OOP_ARRAYINT_H


#include <cassert> // для assert()
#include <cstring>
#include <iostream>

using namespace std;

/*
 * 1. Добавить в контейнерный класс, который был написан в этом уроке, методы:
 *      • для удаления последнего элемента массива (аналог функции pop_back() в векторах)
 *      • для удаления первого элемента массива (аналог pop_front() в векторах)
 *      • для сортировки массива
 *      • для вывода на экран элементов.
 */

class ArrayInt
{
private:
    int m_length;
    int *m_data;

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

public:
    ArrayInt(): m_length(0), m_data(nullptr)    { }

    ArrayInt(int length): m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        // Здесь нам нужно указать m_data значение nullptr, чтобы на выходе не было висячего указателя
        m_data = nullptr;
        m_length = 0;
    }
    int getLength() { return m_length; }
    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    void resize(int newLength)
    {
        // Если массив уже нужной длины — return
        if (newLength == m_length)
            return;

        // Если нужно сделать массив пустым — делаем это и затем return
        if (newLength <= 0)
        {
            erase();
            return;
        }

        // Теперь знаем, что newLength >0
        // Выделяем новый массив
        int *data = new int[newLength];

        // Затем нужно разобраться с количеством копируемых элементов в новый массив
        // Нужно скопировать столько элементов, сколько их есть в меньшем из массивов
        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            // Поочередно копируем элементы
            for (int index=0; index < elementsToCopy ; ++index)
                data[index] = m_data[index];
        }

        // Удаляем старый массив, так как он нам уже не нужен
        delete[] m_data;

        // И используем вместо старого массива новый! Обратите внимание, m_data указывает
        // на тот же адрес, на который указывает наш новый динамически выделенный массив. Поскольку
        // данные были динамически выделенные — они не будут уничтожены, когда выйдут из области видимости
        m_data = data;
        m_length = newLength;
    }
    void insertBefore(int value, int index)
    {
        // Проверка корректности передаваемого индекса
        assert(index >= 0 && index <= m_length);

        // Создаем новый массив на один элемент больше старого массива
        int *data = new int[m_length+1];

        // Копируем все элементы до index-а
        for (int before=0; before < index; ++before)
            data[before] = m_data[before];

        // Вставляем новый элемент в новый массив
        data [index] = value;

        // Копируем все значения после вставляемого элемента
        for (int after=index; after < m_length; ++after)
            data[after+1] = m_data[after];

        // Удаляем старый массив и используем вместо него новый
        delete[] m_data;
        m_data = data;
        ++m_length;
    }
    void push_back(int value) { insertBefore(value, m_length); }

//relate to homework
    void removeLast();
    void removeFirst();
    void sortDown();
    void sortUp();
    void showElements();
};

#endif //OOP_ARRAYINT_H
