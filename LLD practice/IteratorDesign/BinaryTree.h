#pragma once
#include "Iterable.h"
class BinaryTree : public Iterable<int> {
    public:
        int data;
        BinaryTree* left;
        BinaryTree* right;

        BinaryTree(int value){
            data = value;
            left = nullptr;
            right = nullptr;
        }

        Iterator<int>* getIterator() override;
};

