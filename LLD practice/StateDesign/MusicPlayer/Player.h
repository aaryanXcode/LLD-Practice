#pragma once
#include "IPlayerState.h"

// Forward declarations of state classes only
class StoppedState;
class PlayingState;
class NextPlayState;
class PreviousPlayingState;
class ResumeState;
class PauseState;
class NoPlayingState;
class NoMusicState;
class HasMusicState;

class Player {
private:
    IPlayerState* currentstate;

    int totalsong;
    int playcurrent;

    IPlayerState* stoppedstate;
    IPlayerState* playingstate;
    IPlayerState* nextplaystate;
    IPlayerState* previousPlaystate;
    IPlayerState* resumestate;
    IPlayerState* pausestate;
    IPlayerState* noplayingstate;
    IPlayerState* nomusicState;
    IPlayerState* hasMusicState;

public:
    // ✅ Constructor & Destructor declared here, defined in Player.cpp
    Player(int totalsong, int playcurrent);
    ~Player();

    void setState(IPlayerState* state);

    // Getters for each state
    IPlayerState* getStoppedState();
    IPlayerState* getPlayingState();
    IPlayerState* getNextPlayState();
    IPlayerState* getPreviousPlayState();
    IPlayerState* getResumeState();
    IPlayerState* getPauseState();
    IPlayerState* getNoPlayingState();
    IPlayerState* getNoMusicState();
    IPlayerState* getHasMusicState();

    // Music info
    int getTotalSong() const;
    int getPlayCurrent() const;
    void setTotalSong(int song);
    void setPlayCurrent(int current);

    // 🎯 Delegate to current state
    void play();
    void stop();
    void playNext();
    void playPrevious();
};
