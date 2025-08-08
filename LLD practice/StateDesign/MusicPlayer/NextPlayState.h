#pragma once 
#include "IPlayerState.h"
#include <iostream>
#include "Player.h" // Ensure Player class is included for type reference
class NextPlayState:public IPlayerState{
    public:
        void play(Player* p) override {
            if (p->getTotalSong() > 0) {
                std::cout << "Music loaded. Starting song " << p->getPlayCurrent() << "." << std::endl;
                p->setState(p->getPlayingState());
            } else {
                std::cout << "No music available to play." << std::endl;
            }
        }

        void stop(Player* p) override {
            std::cout << "Music stopped." << std::endl;
            p->setState(p->getStoppedState());
        }

        void playNext(Player* p) override {
            std::cout << "Already playing next song." << std::endl;
        }

        void playPrevious(Player* p) override {
            std::cout << "Playing previous song." << std::endl;
            p->setState(p->getPreviousPlayState());
        }

};