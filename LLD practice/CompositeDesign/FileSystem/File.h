#pragma once
#include "FileSystem.h"
#include<bits/stdc++.h>
using namespace std;
class File:public FileSystem{
    int size;
    string name;
    public:
        File(const string& name,int size){
            this->name = name;
            this->size = size;
        }

        void ls() override {
            return ;
        }  

        void openAll() override {
            cout<<"   |->"<<name<<endl;
        }  

        int getSize() override {
            return size;
        }              
        FileSystem* cd(const string& name) override {
            return nullptr;
        }
        string getName() override {
            return this->name;
        }
        bool isFolder() override {
            return false;
        }
};