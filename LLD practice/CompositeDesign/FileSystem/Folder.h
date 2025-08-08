#pragma once
#include "FileSystem.h"
#include<bits/stdc++.h>
using namespace std;
class Folder:public FileSystem{
    string name;
    int size;
    vector<FileSystem*> filesSystem;
    public:
        
        Folder(const string& name){
            this->name = name;
        }

        ~Folder() {
            for (auto c : filesSystem) delete c;
        }

        void add(FileSystem* item) {
            filesSystem.push_back(item);
        }

        void ls() override {
            for(auto child:filesSystem){
                cout<<"    "<<child->getName()<<endl;
            }
        }          
        void openAll() override {
            cout <<" "<< "+ " << name << "\n";
            for(auto obj:filesSystem){
                obj->openAll();
            }
        }  

        int getSize() override {
            int totalSize = 0;
            for (auto obj : filesSystem) {
                totalSize += obj->getSize();
            }
            return totalSize;
        }              
        FileSystem* cd(const string& target) override {
            for (auto obj : filesSystem) {
            if (obj->isFolder() && obj->getName() == target) {
                    return obj;
                }
            }
            // not found or not a folder
            return nullptr;
        }
        string getName() override {
            return this->name;
        }

        bool isFolder() override {
            return true;
        }
};