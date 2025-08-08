#pragma once 
#include "IPlayerState.h"
#include <iostream>
#include "Player.h"

class NoMusicState : public IPlayerState {
public:
    void play(Player* p) override {
        if (p->getTotalSong() > 0) {
            std::cout << "Starting playback from song " << p->getPlayCurrent() << "." << std::endl;
            p->setState(p->getPlayingState());
        } else {
            std::cout << "No songs available to play." << std::endl;
            p->setState(p->getNoMusicState());
        }
    }

    void stop(Player* p) override {
        std::cout << "Nothing is currently playing." << std::endl;
    }

    void playNext(Player* p) override {
        std::cout << "Please start playing first before using next." << std::endl;
    }

    void playPrevious(Player* p) override {
        std::cout << "Please start playing first before using previous." << std::endl;
    }
};
