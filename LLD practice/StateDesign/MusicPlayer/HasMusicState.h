#pragma once 
#include "IPlayerState.h"
#include <iostream>
#include "Player.h"

class HasMusicState : public IPlayerState {
public:
    void play(Player* p) override {
        std::cout << "Playing music from song " << p->getPlayCurrent() << "." << std::endl;
        p->setState(p->getPlayingState());
    }

    void stop(Player* p) override {
        std::cout << "Music is loaded but not playing. Nothing to stop." << std::endl;
    }

    void playNext(Player* p) override {
        if (p->getPlayCurrent() + 1 < p->getTotalSong()) {
            p->setPlayCurrent(p->getPlayCurrent() + 1);
            std::cout << "Ready to play next song: " << p->getPlayCurrent() << "." << std::endl;
        } else {
            std::cout << "Already at last song. Cannot go to next." << std::endl;
        }
        // Optionally stay in this state or go to PlayingState
        p->setState(p->getNextPlayState());
    }

    void playPrevious(Player* p) override {
        if (p->getPlayCurrent() > 0) {
            p->setPlayCurrent(p->getPlayCurrent() - 1);
            std::cout << "Ready to play previous song: " << p->getPlayCurrent() << "." << std::endl;
        } else {
            std::cout << "Already at first song. Cannot go to previous." << std::endl;
        }
        p->setState(p->getPreviousPlayState());
    }
};
