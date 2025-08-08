#pragma once
#include "Iterator.h"
#include "Song.h"

#include<bits/stdc++.h>
using namespace std;
class PlayListIterator : public Iterator<Song> {
private:
    vector<Song> vec;
    size_t index;
public:
    PlayListIterator(vector<Song> v) {
        vec = v;
        index = 0;
    }

    bool hasNext() override {
        return index < vec.size();
    }

    Song next() override {
        return vec[index++];
    }
};