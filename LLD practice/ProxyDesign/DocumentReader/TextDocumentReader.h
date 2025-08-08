#pragma once
#include "IDocument.h"
#include<bits/stdc++.h>
using namespace std;
class TextDocumentReader:public IDocument{
    string filename;
    
    
    public:
        TextDocumentReader(string name){
            this->filename = name;
        }

        void read() override{
            cout<<"filename:"<<this->filename<<" \n"<<"content:"<<"Hii there , How are you"<<endl;
        }
};