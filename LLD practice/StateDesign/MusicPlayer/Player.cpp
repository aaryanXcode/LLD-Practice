#include "Player.h"

// Full definitions (not just forward declarations)
#include "StoppedState.h"
#include "PlayingState.h"
#include "NextPlayState.h"
#include "PreviousPlayingState.h"
#include "ResumeState.h"
#include "PauseState.h"
#include "NoPlayingState.h"
#include "NoMusicState.h"
#include "HasMusicState.h"

Player::Player(int totalsong, int playcurrent)
    : totalsong(totalsong), playcurrent(playcurrent)
{
    stoppedstate = new StoppedState();
    playingstate = new PlayingState();
    nextplaystate = new NextPlayState();
    previousPlaystate = new PreviousPlayingState();
    resumestate = new ResumeState();
    pausestate = new PauseState();
    noplayingstate = new NoPlayingState();
    nomusicState = new NoMusicState();
    hasMusicState = new HasMusicState();

    currentstate = (totalsong > 0) ? noplayingstate : nomusicState;
}

Player::~Player() {
    delete stoppedstate;
    delete playingstate;
    delete nextplaystate;
    delete previousPlaystate;
    delete resumestate;
    delete pausestate;
    delete noplayingstate;
    delete nomusicState;
    delete hasMusicState;
}

void Player::setState(IPlayerState* state) { currentstate = state; }

IPlayerState* Player::getStoppedState()      { return stoppedstate; }
IPlayerState* Player::getPlayingState()      { return playingstate; }
IPlayerState* Player::getNextPlayState()     { return nextplaystate; }
IPlayerState* Player::getPreviousPlayState() { return previousPlaystate; }
IPlayerState* Player::getResumeState()       { return resumestate; }
IPlayerState* Player::getPauseState()        { return pausestate; }
IPlayerState* Player::getNoPlayingState()    { return noplayingstate; }
IPlayerState* Player::getNoMusicState()      { return nomusicState; }
IPlayerState* Player::getHasMusicState()     { return hasMusicState; }

int Player::getTotalSong() const { return totalsong; }
int Player::getPlayCurrent() const { return playcurrent; }
void Player::setTotalSong(int song) { totalsong = song; }
void Player::setPlayCurrent(int current) { playcurrent = current; }

void Player::play()         { currentstate->play(this); }
void Player::stop()         { currentstate->stop(this); }
void Player::playNext()     { currentstate->playNext(this); }
void Player::playPrevious() { currentstate->playPrevious(this); }
