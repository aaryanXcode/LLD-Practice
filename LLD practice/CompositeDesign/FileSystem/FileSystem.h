#pragma once
#include<bits/stdc++.h>
using namespace std;
class FileSystem{
    public: 
        virtual string getName() = 0;
        virtual int getSize() = 0;
        virtual void ls() = 0;
        virtual FileSystem* cd(const string& name) =0;
        virtual void openAll() = 0;
        virtual ~FileSystem(){}
        virtual bool isFolder() = 0;
};