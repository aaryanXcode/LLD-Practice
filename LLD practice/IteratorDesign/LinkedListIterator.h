#pragma once
#include "Iterator.h"
#include "LinkedList.h"

class LinkedListIterator:public Iterator<int>{
    private:
        LinkedList* current;
    public:
        LinkedListIterator(LinkedList* head){
            current = head;
        }
        bool hasNext() override{
            return current != nullptr;
        }

        int next() override{
            int val = current->data;
            current = current->next;
            return val;
        }

        
};
