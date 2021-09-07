//
// Created by Tr on 07.09.2021.
//

#include "ArrayInt.h"

void ArrayInt::removeLast() {
    if (m_length == 0) {
        return;
    }

    int* data = new int [m_length-1];
    memcpy(data, m_data, (m_length-1)*sizeof(int));
    delete [] m_data;
    m_data = data;
    --m_length;
}

void ArrayInt::removeFirst() {
    if (m_length == 0) {
        return;
    }

    int* data = new int [m_length-1];
    memcpy(data, &m_data[1], (m_length-1)*sizeof(int));
    delete [] m_data;
    m_data = data;
    --m_length;
}

void ArrayInt::sortDown() {
    //simple insertion sort
    for (int i = 0; i < m_length-1; i++) {
        int ind_max = i;
        for (int j = i+1; j < m_length; j++) {
            if (m_data[j] > m_data[ind_max]) {
                ind_max = j;
            }
        }
        swap(m_data[ind_max], m_data[i]);
    }

}

void ArrayInt::sortUp() {
    //simple insertion sort
    for (int i = 0; i < m_length-1; i++) {
        int ind_min = i;
        for (int j = i+1; j < m_length; j++) {
            if (m_data[j] < m_data[ind_min]) {
                ind_min = j;
            }
        }
        swap(m_data[ind_min], m_data[i]);
    }
}

void ArrayInt::showElements() {
    if (m_length == 0) {
        cout << "no elements";
    }
    for (int i = 0; i < m_length; i++) {
        cout << m_data[i] << " ";
    }
    cout << endl;
}
