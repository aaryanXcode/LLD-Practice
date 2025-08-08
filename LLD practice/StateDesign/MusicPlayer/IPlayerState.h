#pragma once

class Player;

class IPlayerState{
    public:
        virtual void play(Player* p) = 0 ;
        virtual void stop(Player* p) = 0;
        virtual void playNext(Player* p) = 0;
        virtual void playPrevious(Player* p) = 0;

};