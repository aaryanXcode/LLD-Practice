#pragma once
#include "IDisplay.h"
#include<bits/stdc++.h>
using namespace std;
class ImageDisplay:public IDisplay{
    string filename;
    public:
        ImageDisplay(string name){
            this->filename = name;
            cout<<"Loading the image:"<<name<<endl;
        }

        void display() override {
            cout<<"displaying image:"<<this->filename<<endl;
        }
};