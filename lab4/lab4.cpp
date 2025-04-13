#include <cassert>
#include <string>
#include <iostream>

#include "Sequence.h"

int main() {
    Sequence<int> seq;

    assert(seq.getSize() == 0);
    assert(!seq.contains(5));

    seq.add(5);
    seq.add(10);
    seq.add(15);

    assert(seq.getSize() == 3);
    assert(seq.contains(5));
    assert(seq.contains(10));
    assert(!seq.contains(99));

    assert(seq.remove(10));
    assert(!seq.contains(10));
    assert(seq.getSize() == 2);

    assert(!seq.remove(99)); // нічого не видалили
    assert(seq.getSize() == 2);

    seq.add(20);
    assert(seq.contains(20));
    assert(seq.getSize() == 3);

    Sequence<std::string> strSeq;
    strSeq.add("hello");
    strSeq.add("world");

    assert(strSeq.contains("hello"));
    assert(!strSeq.contains("bye"));
    assert(strSeq.getSize() == 2);
    assert(strSeq.remove("hello"));
    assert(!strSeq.contains("hello"));

    std::cout << "All is good";
}