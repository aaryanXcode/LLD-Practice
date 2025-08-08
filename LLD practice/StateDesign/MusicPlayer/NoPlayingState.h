#pragma once 
#include "IPlayerState.h"
#include <iostream>
#include "Player.h" // Ensure Player class is included for type reference
class NoPlayingState:public IPlayerState{
    public:
        void play(Player* p) override {
            std::cout << "No music to play. Please load music first." << std::endl;
        }

        void stop(Player* p) override {
            std::cout << "No music is currently playing." << std::endl;
        }

        void playNext(Player* p) override {
            std::cout << "No music to play next. Please load music first." << std::endl;
        }

        void playPrevious(Player* p) override {
            std::cout << "No music to play previous. Please load music first." << std::endl;
        }
        // Additional methods can be added here if needed

};