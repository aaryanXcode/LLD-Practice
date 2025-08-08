#pragma once 
#include "IPlayerState.h"
#include <iostream>
#include "Player.h" // Ensure Player class is included

class ResumeState : public IPlayerState {
public:
    void play(Player* p) override {
        std::cout << "Resuming music from song " << p->getPlayCurrent() << "." << std::endl;
        p->setState(p->getPlayingState());
    }

    void stop(Player* p) override {
        std::cout << "Music stopped from resume state." << std::endl;
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
        if (p->getPlayCurrent() > 0) {
            p->setPlayCurrent(p->getPlayCurrent() - 1);
            std::cout << "Playing previous song: " << p->getPlayCurrent() << std::endl;
            p->setState(p->getPlayingState());
        } else {
            std::cout << "Already at first song. Cannot play previous." << std::endl;
        }
    }
};
