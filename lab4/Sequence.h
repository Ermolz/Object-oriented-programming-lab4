#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <cstddef>
#include <algorithm>
#include <string>

template <typename T>
class Sequence {
private:
    T* data;
    size_t capacity;
    size_t size;

    void resize();

public:
    Sequence();
    ~Sequence();

    void add(const T& value);
    bool remove(const T& value);
    bool contains(const T& value) const;
    size_t getSize() const;
};

#endif
