//
// Created by Tr on 29.07.2021.
//

#ifndef CPP_PROJ_STACK_FIFO_H
#define CPP_PROJ_STACK_FIFO_H

#include <iostream>
#include <cstring>

/*    3. Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
        ◦ private-массив   целых чисел длиной 10;
        ◦ private целочисленное значение для отслеживания длины стека;
        ◦ public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
        ◦ public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
        ◦ public-метод с именем getEl() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться   предупреждение;
        ◦ public-метод с именем print(), который будет выводить все значения стека.
*/

template<typename T>
class FIFO {
private:
    T *fifo_data;
    int size;
    int last_el_index;
public:
    FIFO() : size(10), last_el_index(-1) {
        fifo_data = new T [size];
        memset(fifo_data, 0x00, size * sizeof(T));
    }
    FIFO(int size_) : size(size_), last_el_index(-1) {
        fifo_data = new T [size_];
        memset(fifo_data, 0x00, size_ * sizeof(T));
    }
    ~FIFO() {
        delete [] fifo_data;
    }

    bool push(const T& el);
    bool getEl(T& el);
    bool pop();

    void reset();

    int print() {
        cout << "(";
        for (int i = 0; i < last_el_index+1; i++) {
            std::cout << fifo_data[i];
            if (i != last_el_index) {
                cout << " ";
            }
        }
        cout << ")" << endl;
        return last_el_index;
    }
};

template<typename T>
bool FIFO<T>::push(const T& el) {
    if (last_el_index == size) {
        return false;
    }
    fifo_data[++last_el_index] = el;
    return true;
}
template<typename T>
bool FIFO<T>::getEl(T &el) {
    if (last_el_index < 0) {
        return false;
    }

    el = fifo_data[0];

    for (int i = 1; i < last_el_index+1; i++) {
        fifo_data[i-1] = fifo_data[i];
    }

    fifo_data[last_el_index] = 0;

    --last_el_index;

    return true;
}

template<typename T>
void FIFO<T>::reset() {
//    while(pop() == true);   //very slow
    memset(fifo_data, 0x00, size*sizeof (T));
    last_el_index = 0;
}

template<typename T>
bool FIFO<T>::pop() {
    if (last_el_index < 0) {
        return false;
    }

    for (int i = 1; i < last_el_index+1; i++) {
        fifo_data[i-1] = fifo_data[i];
    }

    fifo_data[last_el_index] = 0;

    --last_el_index;

    return true;
}


#endif //CPP_PROJ_STACK_FIFO_H
