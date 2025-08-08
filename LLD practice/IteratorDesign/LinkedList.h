#pragma once
#include "Iterable.h"
#include "Iterator.h"
#include "LinkedListIterator.h"
class LinkedList : public Iterable<int> {
public:
    int data;
    LinkedList* next;

    LinkedList(int value) {
        data = value;
        next = nullptr;
    }

    Iterator<int>* getIterator() override;
};

Iterator<int>* LinkedList::getIterator() {
    return new LinkedListIterator(this);
}


