#pragma once
#include "IPlayerState.h"
#include "Player.h"
#include <iostream>

class StoppedState : public IPlayerState {
public:
    void play(Player* p) override {
        if (p->getTotalSong() == 0) {
            std::cout << "Cannot play. No songs available." << std::endl;
            p->setState(p->getNoMusicState());
        } else {
            std::cout << "Starting song: " << p->getPlayCurrent() << std::endl;
            p->setState(p->getPlayingState());
        }
    }

    void stop(Player* p) override {
        std::cout << "Music is already stopped." << std::endl;
    }

    void playNext(Player* p) override {
        std::cout << "Cannot play next. Music is stopped." << std::endl;
    }

    void playPrevious(Player* p) override {
        std::cout << "Cannot play previous. Music is stopped." << std::endl;
    }
};
