#pragma once
#include "Song.h"
#include "Iterable.h"
#include "PlayListIterator.h"
class Playlist : public Iterable<Song>{
    public:
        vector<Song> songs;
        void addSong(const Song& s){
            songs.push_back(s);
        }

        Iterator<Song>* getIterator() override;
};
Iterator<Song>* Playlist::getIterator() {
    return new PlayListIterator(songs);
}
