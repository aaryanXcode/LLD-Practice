#pragma once
template<typename T>
class Iterator; // forward declaration

template<typename T>
class Iterable {
public:
    virtual Iterator<T>* getIterator() = 0;
};