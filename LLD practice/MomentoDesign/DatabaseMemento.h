#pragma once
#include<bits/stdc++.h>
using namespace std;
class DatabaseMemento {
private:
    map<string, string> data;
    
public:
    DatabaseMemento(const map<string, string>& dbData) {
        this->data = dbData;
    }
    
    map<string, string> getState() const {
        return data;
    }
};