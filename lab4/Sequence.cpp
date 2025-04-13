#include "Sequence.h"

template <typename T>
Sequence<T>::Sequence() : data(nullptr), capacity(0), size(0) {}

template <typename T>
Sequence<T>::~Sequence() {
    delete[] data;
}

template <typename T>
void Sequence<T>::resize() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    T* newData = new T[capacity];

    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
}

template <typename T>
void Sequence<T>::add(const T& value) {
    if (size >= capacity) {
        resize();
    }
    data[size++] = value;
}

template <typename T>
bool Sequence<T>::remove(const T& value) {
    for (size_t i = 0; i < size; ++i) {
        if (data[i] == value) {
            for (size_t j = i; j < size - 1; ++j) {
                data[j] = data[j + 1];
            }
            --size;
            return true;
        }
    }
    return false;
}

template <typename T>
bool Sequence<T>::contains(const T& value) const {
    for (size_t i = 0; i < size; ++i) {
        if (data[i] == value) {
            return true;
        }
    }
    return false;
}

template <typename T>
size_t Sequence<T>::getSize() const {
    return size;
}

template class Sequence<int>;
template class Sequence<double>;
template class Sequence<std::string>;
