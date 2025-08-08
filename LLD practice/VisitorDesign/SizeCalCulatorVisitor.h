#pragma once
#include "IVisitor.h"
#include "Document.h"
#include<bits/stdc++.h>
using namespace std;
class SizeCalCulatorVisitor:public IVisitor{
    
    public:
        void visit(TextFile* doc) override {
            cout<<"calculating text file size"<<endl;
        }

        void visit(ImageFile* image) override {
            cout<<"calculating image size"<<endl;
        }
};