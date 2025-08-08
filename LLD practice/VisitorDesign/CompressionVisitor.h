#pragma once
#include "IVisitor.h"
#include "Document.h"
#include<bits/stdc++.h>
using namespace std;
class CompressionVisitor:public IVisitor{
    
    public:
        void visit(TextFile* doc) override {
            cout<<"Compressing text file "<<endl;
        }

        void visit(ImageFile* image) override {
            cout<<"Compressing image "<<endl;
        }
};