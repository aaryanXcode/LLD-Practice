#pragma once
#include<bits/stdc++.h>
using namespace std;
#include "Iterable.h"

class Song{
    public:
    string title;
    string artist;

    Song(const string& t,const string& a){
        title = t;
        artist =a;
    }
};