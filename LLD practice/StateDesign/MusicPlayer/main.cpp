#include "Player.h"
#include<iostream>
int main() {
    // Create a player with 3 songs, currently at song 0
    Player* player = new Player(3, 0);

    std::cout << "\n--- Initial State ---\n";
    player->play();  // Should transition to PlayingState

    std::cout << "\n--- Play Next ---\n";
    player->playNext();  // Go to next song

    std::cout << "\n--- Play Previous ---\n";
    player->playPrevious();  // Go back to previous

    std::cout << "\n--- Pause Simulation ---\n";
    player->setState(player->getPauseState());  // Simulate pause
    player->play();  // Resume

    std::cout << "\n--- Stop Music ---\n";
    player->stop();  // Transition to StoppedState

    std::cout << "\n--- Try Playing from Stopped State ---\n";
    player->play();  // Play again

    std::cout << "\n--- Go Beyond Last Song ---\n";
    player->playNext();  // Song 1
    player->playNext();  // Song 2
    player->playNext();  // Should not go beyond

    std::cout << "\n--- Try Previous at First Song ---\n";
    player->setPlayCurrent(0);  // Reset to song 0
    player->playPrevious();     // Should stay

    delete player;
    return 0;
}
