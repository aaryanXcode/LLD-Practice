#pragma once 
#include "IPlayerState.h"
#include <iostream>
#include "Player.h"

class PreviousPlayingState : public IPlayerState {
public:
    void play(Player* p) override {
        int current = p->getPlayCurrent();
        if (current > 0) {
            p->setPlayCurrent(current - 1);
            std::cout << "Playing previous song: " << p->getPlayCurrent() << std::endl;
            p->setState(p->getPlayingState());
        } else {
            std::cout << "Already at the first song. Cannot play previous." << std::endl;
            p->setState(p->getPlayingState()); // still resume playback
        }
    }

    void stop(Player* p) override {
        std::cout << "Music stopped from previous song." << std::endl;
        p->setState(p->getStoppedState());
    }

    void playNext(Player* p) override {
        if (p->getPlayCurrent() + 1 < p->getTotalSong()) {
            p->setPlayCurrent(p->getPlayCurrent() + 1);
            std::cout << "Playing next song: " << p->getPlayCurrent() << std::endl;
            p->setState(p->getPlayingState());
        } else {
            std::cout << "Already at last song. Cannot play next." << std::endl;
        }
    }

    void playPrevious(Player* p) override {
        std::cout << "Already playing previous song: " << p->getPlayCurrent() << std::endl;
    }
};
