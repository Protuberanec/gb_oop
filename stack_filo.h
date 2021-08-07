//
// Created by Tr on 07.08.2021.
//

#ifndef OOP_STACK_FILO_H
#define OOP_STACK_FILO_H


#include <iostream>
#include <cstring>

using namespace std;

/*    3. Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
        ◦ private-массив   целых чисел длиной 10;
        ◦ private целочисленное значение для отслеживания длины стека;
        ◦ public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
        ◦ public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
        ◦ public-метод с именем getEl() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться   предупреждение;
        ◦ public-метод с именем print(), который будет выводить все значения стека.
*/

template<typename T>
class FILO {
private:
    T *filo_data;
    int size;
    int last_el_index;
public:
    FILO() : size(10), last_el_index(-1) {
        filo_data = new T [size];
        memset(filo_data, 0x00, size * sizeof(T));
    }
    FILO(int size_) : size(size_), last_el_index(-1) {
        filo_data = new T [size_];
        memset(filo_data, 0x00, size_ * sizeof(T));
    }
    ~FILO() {
        delete [] filo_data;
    }

    bool push(const T& el);
    bool getEl(T& el);
    bool pop();

    void reset();

    int print() {
        cout << "(";
        for (int i = 0; i < last_el_index+1; i++) {
            std::cout << filo_data[i];
            if (i != last_el_index) {
                cout << " ";
            }
        }
        cout << ")" << endl;
        return last_el_index;
    }
};

template<typename T>
bool FILO<T>::push(const T& el) {
    if (last_el_index >= size-1) {
        return false;
    }
    filo_data[++last_el_index] = el;
    return true;
}
template<typename T>
bool FILO<T>::getEl(T &el) {
    if (last_el_index < 0) {
        return false;
    }

    el = filo_data[last_el_index];
    filo_data[last_el_index] = 0;

    --last_el_index;

    return true;
}

template<typename T>
void FILO<T>::reset() {
    while(pop() == true);   //reset all values in constructor, and when pop or get elements set value to zero
}

template<typename T>
bool FILO<T>::pop() {
    if (last_el_index < 0) {
        return false;
    }

    filo_data[last_el_index] = 0;

    --last_el_index;

    return true;
}


#endif //OOP_STACK_FILO_H
